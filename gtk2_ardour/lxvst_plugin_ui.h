/*
 * Copyright (C) 2011-2015 Paul Davis <paul@linuxaudiosystems.com>
 * Copyright (C) 2013-2017 Robin Gareus <robin@gareus.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#pragma once

#include "pbd/signals.h"
#include "vst_plugin_ui.h"

#ifdef LXVST_SUPPORT

namespace ARDOUR {
	class PlugInsertBase;
	class LXVSTPlugin;
}

class LXVSTPluginUI : public VSTPluginUI
{
public:
	LXVSTPluginUI (std::shared_ptr<ARDOUR::PlugInsertBase>, std::shared_ptr<ARDOUR::VSTPlugin>);
	~LXVSTPluginUI ();

	int get_preferred_height ();

	bool start_updating (GdkEventAny*) { return false; }
	bool stop_updating (GdkEventAny*) { return false; }

	int package (Gtk::Window&);
	void forward_key_event (GdkEventKey *);
	bool non_gtk_gui () const { return true; }

private:
	void resize_callback ();
	int get_XID ();

	PBD::ScopedConnection _resize_connection;
};

#endif //LXVST_SUPPORT

