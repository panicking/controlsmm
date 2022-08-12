#include <gtkmm.h>
#include <gtkmm/entry.h>
#include <glibmm/datetime.h>
#include "datelabel.h"

namespace components {

    dateLabel::dateLabel() : Gtk::Label(),
		    Glib::ObjectBase("dateLabel")
    {
        date_slot = sigc::mem_fun(*this, &dateLabel::on_timeout_update_time);
        on_timeout_update_time();
    }

    dateLabel::dateLabel(BaseObjectType* cobject,
		    const Glib::RefPtr<Gtk::Builder>& builder) : Gtk::Label(cobject),
		    Glib::ObjectBase("dateLabel")
    {
        date_slot = sigc::mem_fun(*this, &dateLabel::on_timeout_update_time);
        on_timeout_update_time();
    }

    void dateLabel::on_timeout_update_time(void)
    {
        Glib::ustring str;
        Glib::DateTime now = Glib::DateTime::create_now_local();

        str = now.format("%I:%M %p");
        set_text(str);

        Glib::signal_timeout().connect_seconds_once(date_slot, 60 - now.get_second());
    }

    dateLabel::~dateLabel()
    {
        date_slot.disconnect();
    }
}
