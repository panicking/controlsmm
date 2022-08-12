#include <gtkmm.h>
#include <gtkmm/entry.h>
#include "wifisignalicon.h"

namespace components {

    wifiSignalIcon::wifiSignalIcon() : Gtk::Image(),
		    Glib::ObjectBase("wifiSignalIcon"), connected(false)
    {

    };

    wifiSignalIcon::wifiSignalIcon(BaseObjectType* cobject,
		    const Glib::RefPtr<Gtk::Builder>& builder) : Gtk::Image(cobject),
		    Glib::ObjectBase("wifiSignalIcon"), connected(false)
    {

    };

    void wifiSignalIcon::set_wifi_signal_level(int strength)
    {
        strength = std::clamp<int>(strength, WifiLevel::LOW_SIGNAL, 0);

        switch (strength)
        {
        case WifiLevel::HIGH_SIGNAL:
            set_from_resource("/controls/assets/wifi-signal-4.svg");
            break;
        case WifiLevel::MEDIUM_SIGNAL ... WifiLevel::HIGH_SIGNAL - 1:
            set_from_resource("/controls/assets/wifi-signal-3.svg");
            break;
        case WifiLevel::MEDIUM_LOW_SIGNAL ... WifiLevel::MEDIUM_SIGNAL - 1:
            set_from_resource("/controls/assets/wifi-signal-2.svg");
            break;
        case WifiLevel::LOW_SIGNAL ... WifiLevel::MEDIUM_LOW_SIGNAL - 1:
            set_from_resource("/controls/assets/wifi-signal-1.svg");
            break;
        default:
            set_from_resource("/controls/assets/wifi-signal-0.svg");
            break;
        }

        wifiStrength = strength;
    }
}
