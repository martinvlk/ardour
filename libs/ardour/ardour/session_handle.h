/*
 * Copyright (C) 2009-2017 Paul Davis <paul@linuxaudiosystems.com>
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

#include "ardour/libardour_visibility.h"

namespace ARDOUR {
	class Session;

class LIBARDOUR_API SessionHandleRef : public PBD::ScopedConnectionList
{
  public:
	SessionHandleRef (ARDOUR::Session& s);
	virtual ~SessionHandleRef ();

  protected:
	ARDOUR::Session&          _session;
	virtual void session_going_away ();
	virtual void insanity_check ();
};

class LIBARDOUR_API SessionHandlePtr
{
  public:
	SessionHandlePtr (ARDOUR::Session* s);
	SessionHandlePtr () : _session (0) {}
	virtual ~SessionHandlePtr () {}

	virtual void set_session (ARDOUR::Session *);
	virtual ARDOUR::Session* session() const { return _session; }

  protected:
	ARDOUR::Session*          _session;
	PBD::ScopedConnectionList _session_connections;

	virtual void session_going_away ();
};

} /* namespace */

