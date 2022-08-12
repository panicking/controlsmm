#pragma once
#include <glib.h>
#include <gtkmm.h>
#include <glibmm/datetime.h>
#include <gtkmm/label.h>
#include <sigc++/sigc++.h>

namespace components {

  class dateLabel : public Gtk::Label {
    public:
    dateLabel();
    dateLabel(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
    virtual ~dateLabel();

    Glib::PropertyProxy<bool> use_ampm() { return prop_use_ampm.get_proxy(); };

    protected:
    void on_timeout_update_time();

    private:
    sigc::slot<void(void)> date_slot;
    Glib::Property<bool> prop_use_ampm;
  };
}
