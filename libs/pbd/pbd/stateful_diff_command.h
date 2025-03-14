/*
 * Copyright (C) 2010-2015 Paul Davis <paul@linuxaudiosystems.com>
 * Copyright (C) 2010 Carl Hetherington <carl@carlh.net>
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

#include <memory>

#include "pbd/command.h"
#include "pbd/libpbd_visibility.h"

namespace PBD
{
class StatefulDestructible;
class PropertyList;

/** A Command which stores its action as the differences between the before and after
 *  state of a Stateful object.
 */
class LIBPBD_API StatefulDiffCommand : public PBD::Command
{
public:
	StatefulDiffCommand (std::shared_ptr<StatefulDestructible>);
	StatefulDiffCommand (std::shared_ptr<StatefulDestructible>, XMLNode const&);
	~StatefulDiffCommand ();

	void operator() ();
	void undo ();

	XMLNode& get_state () const;

	bool empty () const;

private:
	std::weak_ptr<Stateful> _object;  ///< the object in question
	PBD::PropertyList*        _changes; ///< property changes to execute this command
};

}; // namespace PBD

