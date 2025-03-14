/*
 * Copyright (C) 2008-2014 David Robillard <d@drobilla.net>
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

#include <list>

#include "ardour/automation_list.h"
#include "evoral/Parameter.h"

class AutomationSelection : public std::list<std::shared_ptr<ARDOUR::AutomationList> > {
public:
	const_iterator
	get_nth(const Evoral::Parameter& param, size_t nth) const {
		size_t count = 0;
		for (const_iterator l = begin(); l != end(); ++l) {
			if ((*l)->parameter() == param) {
				if (count++ == nth) {
					return l;
				}
			}
		}
		return end();
	}
};

