#include <QtSerialPort/QtSerialPort>
#include <QtWidgets/QApplication>
#include <QString>
#include <iostream>
#include <cmath>
#include <functional>

#include <unistd.h>

#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>

#include <zmq.hpp>

#include <messages/servo_action.hpp>
#include <messages/endpoint_action.hpp>

using namespace std;

template<typename T>
void send(zmq::socket_t& sock_pub, T& ea) {
  stringstream oss;

  {
    cereal::BinaryOutputArchive ar(oss);
    ar(ea);
  }

  zmq::message_t msg(oss.str().size());
  oss.str().copy((char*)msg.data(), msg.size());

  sock_pub.send(msg);
}

struct WalkConfig {
  double offset_x = -10;
  double half_esp_x = 140;

  double offset_y = 0;
  double half_esp_y = 120;

  double default_z = -180;
  double delta_z = 40;

  double period = 2;

  double step_up_ratio = 0.3;
  double move_ratio = 0.25;

  double step_size = 60;
};

struct LegConfig {
  double default_x;
  double default_y;
  double default_z;
};

double add_mod(double val, double add, double mod) {
  if(val + add > mod) {
      return val+add-mod;
    }
  return val+add;
}

void get_walk_pos_1(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z) {

  double t_step1_middle = cfg.period / 4.0;
  double t_step2_middle = cfg.period * 3.0 / 4.0;

  double dt_half_step = cfg.period / 4.0;

  y = leg.default_y;

  if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
      double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
      x = leg.default_x + t2*cfg.step_size/2.0;
    }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
      double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
      x = leg.default_x - t2*cfg.step_size/2.0;
    }
  else if(abs(t - cfg.period/2.0) < dt_half_step) {
      x = leg.default_x + cfg.step_size/2.0;
    }
  else if(abs(t - cfg.period/2.0) > dt_half_step) {
      x = leg.default_x - cfg.step_size/2.0;
    }
  else {
      x = leg.default_x;
    }

  if(abs(t - t_step1_middle) < dt_half_step * cfg.step_up_ratio) {
      z = leg.default_z+cfg.delta_z;
    }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.step_up_ratio) {
      z = leg.default_z;
    }
  else {
      z = leg.default_z;
    }

}

void get_walk_pos_2(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z) {

  double t_step1_middle = cfg.period / 4.0;
  double t_step2_middle = cfg.period * 3.0 / 4.0;

  double dt_half_step = cfg.period / 4.0;

  y = leg.default_y;

  if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
      double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
      x = leg.default_x - t2*cfg.step_size/2.0;
    }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
      double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
      x = leg.default_x + t2*cfg.step_size/2.0;
    }
  else if(abs(t - cfg.period/2.0) < dt_half_step) {
      x = leg.default_x - cfg.step_size/2.0;
    }
  else if(abs(t - cfg.period/2.0) > dt_half_step) {
      x = leg.default_x + cfg.step_size/2.0;
    }
  else {
      x = leg.default_x;
    }

  if(abs(t - t_step1_middle) < dt_half_step * cfg.step_up_ratio) {
      z = leg.default_z;
    }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.step_up_ratio) {
      z = leg.default_z+cfg.delta_z;
    }
  else {
      z = leg.default_z;
    }

}

int main(int, char**) {
  // IO config
  zmq::context_t ctx(5);

  zmq::socket_t sock_ik_out(ctx, ZMQ_PUB);
  sock_ik_out.connect("ipc://ik.out");

  zmq::socket_t sock_servo_out(ctx, ZMQ_PUB);
  sock_servo_out.connect("ipc://servo.out");

  {
    int hwm = 8;
    sock_ik_out.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
  }

  WalkConfig cfg;

  LegConfig lf = {
     cfg.half_esp_x+cfg.offset_x,
     cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig rf = {
     cfg.half_esp_x+cfg.offset_x,
    -cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig lb = {
    -cfg.half_esp_x+cfg.offset_x,
     cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig rb = {
    -cfg.half_esp_x+cfg.offset_x,
    -cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  double t = 0;
  while(1) {
      usleep(50000);
      t = add_mod(t, 0.05, cfg.period);
      EndpointAction ea;

      ea.label = "LF";
      ea.enable = true;
      get_walk_pos_1(cfg, lf, t, ea.x, ea.y, ea.z);
      send(sock_ik_out, ea);

      ea.label = "RF";
      ea.enable = true;
      get_walk_pos_2(cfg, rf, t, ea.x, ea.y, ea.z);
      send(sock_ik_out, ea);

      ea.label = "LB";
      ea.enable = true;
      get_walk_pos_2(cfg, lb, t, ea.x, ea.y, ea.z);
      send(sock_ik_out, ea);

      ea.label = "RB";
      ea.enable = true;
      get_walk_pos_1(cfg, rb, t, ea.x, ea.y, ea.z);
      send(sock_ik_out, ea);

      //cout << ea.x << " " << ea.y << " " << ea.z << endl;

    }

  return 0;
}
