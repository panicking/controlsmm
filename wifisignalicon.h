#pragma once
#include <gtkmm/image.h>

namespace components {

  enum WifiLevel {
    NO_SIGNAL = 0,
    LOW_SIGNAL = 40,
    MEDIUM_LOW_SIGNAL = 50,
    MEDIUM_SIGNAL = 55,
    HIGH_SIGNAL = 59,
  };

  class wifiSignalIcon : public Gtk::Image {
    public:
    wifiSignalIcon();
    wifiSignalIcon(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
    virtual ~wifiSignalIcon() {};

    void set_wifi_signal_level(int level);

    private:
    bool connected;
    int wifiStrength;
  };
}
