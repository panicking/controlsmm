#include <gtkmm/entry.h>
#include "datelabel.h"

namespace components {

    dateLabel::dateLabel() : Gtk::Label(), Glib::ObjectBase("dateLabel"),
                prop_use_ampm(*this, "use-ampm", false)
    {
    }

    dateLabel::dateLabel(BaseObjectType* cobject,
                const Glib::RefPtr<Gtk::Builder>& builder) : Gtk::Label(cobject),
                Glib::ObjectBase("dateLabel"),
                prop_use_ampm(*this, "use-ampm", false)
    {
        date_slot = sigc::mem_fun(*this, &dateLabel::on_timeout_update_time);
        use_ampm().signal_changed().connect(sigc::mem_fun(*this, &dateLabel::on_timeout_update_time));
        on_timeout_update_time();
    }

    void dateLabel::on_timeout_update_time()
    {
        Glib::ustring str;
        Glib::DateTime now = Glib::DateTime::create_now_local();

        if (prop_use_ampm)
            str = now.format("%I:%M %p");
        else
            str = now.format("%k:%M");

        set_text(str);

        Glib::signal_timeout().connect_seconds_once(date_slot, 60 - now.get_second());
    }

    dateLabel::~dateLabel()
    {
        date_slot.disconnect();
    }
}
