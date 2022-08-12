#pragma once
#include <glib.h>
#include <gtkmm/label.h>
#include <sigc++/sigc++.h>

namespace components {

  class dateLabel : public Gtk::Label {
    public:
    dateLabel();
    dateLabel(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
    virtual ~dateLabel();

    protected:
    void on_timeout_update_time(void);

    private:
    sigc::slot<void(void)> date_slot;
  };
}
