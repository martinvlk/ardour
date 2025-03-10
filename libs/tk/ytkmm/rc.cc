// Generated by gmmproc 2.45.3 -- DO NOT MODIFY!


#include <glibmm.h>

#include <ytkmm/rc.h>
#include <ytkmm/private/rc_p.h>

#include <ytk/ytk.h>

// -*- c++ -*-
/* $Id: rc.ccg,v 1.3 2004/03/02 21:49:58 murrayc Exp $ */

/* Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <ytkmm/settings.h>
#include <ytkmm/widget.h>
#include <ytkmm/style.h>
#include <ytk/ytk.h>


namespace Gtk
{

void RcStyle::set_name(const Glib::ustring& name)
{
  const Gdk::ScopedPtr<char> old_name (gobj()->name);
  gobj()->name = g_strdup(name.c_str());
}

void RcStyle::set_bg_pixmap_name(StateType state, const Glib::ustring& name)
{
  const Gdk::ScopedPtr<char> old_name (gobj()->bg_pixmap_name[state]);
  gobj()->bg_pixmap_name[state] = g_strdup(name.c_str());
}

Glib::ustring RcStyle::get_bg_pixmap_name(StateType state) const
{
  if(const char *const name = gobj()->bg_pixmap_name[state])
    return Glib::ustring(name);
  else
    return Glib::ustring();
}

void RcStyle::set_font(const Pango::FontDescription& font_desc)
{
  g_return_if_fail(font_desc.gobj() != 0);

  const Pango::FontDescription old_font_desc (gobj()->font_desc, false);
  gobj()->font_desc = font_desc.gobj_copy();
}

Pango::FontDescription RcStyle::get_font() const
{
  return Pango::FontDescription(gobj()->font_desc, true);
}

void RcStyle::set_color_flags(StateType state, RcFlags flags)
{
  gobj()->color_flags[state] = static_cast<GtkRcFlags>(gobj()->color_flags[state] | flags);
}

void RcStyle::unset_color_flags(StateType state, RcFlags flags)
{
  gobj()->color_flags[state] = static_cast<GtkRcFlags>(gobj()->color_flags[state] & ~flags);
}

RcFlags RcStyle::get_color_flags(StateType state) const
{
  return static_cast<RcFlags>(unsigned(gobj()->color_flags[state]));
}

void RcStyle::set_xthickness(int xthickness)
{
  gobj()->xthickness = xthickness;
}

void RcStyle::set_ythickness(int ythickness)
{
  gobj()->ythickness = ythickness;
}


RC::RC(const Glib::ustring& filename)
{
  //gtk_rc_init();
  gtk_rc_parse(filename.c_str());
}

Glib::RefPtr<Style>
RC::get_style(const Widget &widget)
{
  return Glib::wrap(gtk_rc_get_style(const_cast<GtkWidget*>(widget.gobj())));
}

void
RC::parse_string(const Glib::ustring& rc_string)
{
  gtk_rc_parse_string(const_cast<char*>(rc_string.c_str()));
}

bool RC::reparse_all()
{
  return gtk_rc_reparse_all();
}

bool RC::reparse_all(const Glib::RefPtr<Settings>& settings, bool force_load)
{
  return gtk_rc_reparse_all_for_settings(Glib::unwrap(settings), force_load);
}

void RC::reset_styles(const Glib::RefPtr<Settings>& settings)
{
  gtk_rc_reset_styles(Glib::unwrap(settings));        
}

Glib::ustring
RC::find_pixmap_in_path(const Glib::RefPtr<Settings>& context, GScanner *scanner, const Glib::ustring& pixmap_file)
{
  return Glib::convert_return_gchar_ptr_to_ustring(
      gtk_rc_find_pixmap_in_path(Glib::unwrap(context), scanner, const_cast<char*>(pixmap_file.c_str())));
}

Glib::ustring
RC::find_pixmap_in_path(const Glib::RefPtr<Settings>& context, const Glib::ustring& pixmap_file)
{
  return Glib::convert_return_gchar_ptr_to_ustring(
      gtk_rc_find_pixmap_in_path(Glib::unwrap(context), 0 /* see C docs */, const_cast<char*>(pixmap_file.c_str())));
}

Glib::ustring
RC::find_module_in_path(const Glib::ustring& module_file)
{
  return Glib::convert_return_gchar_ptr_to_ustring(
      gtk_rc_find_module_in_path(const_cast<char*>(module_file.c_str())));
}

Glib::ustring
RC::get_module_dir()
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_rc_get_module_dir());
}

}


namespace
{
} // anonymous namespace

// static
GType Glib::Value<Gtk::RcFlags>::value_type()
{
  return gtk_rc_flags_get_type();
}


namespace Glib
{

Glib::RefPtr<Gtk::RcStyle> wrap(GtkRcStyle* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::RcStyle>( dynamic_cast<Gtk::RcStyle*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& RcStyle_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &RcStyle_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_rc_style_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void RcStyle_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* RcStyle_Class::wrap_new(GObject* object)
{
  return new RcStyle((GtkRcStyle*)object);
}


/* The implementation: */

GtkRcStyle* RcStyle::gobj_copy()
{
  reference();
  return gobj();
}

RcStyle::RcStyle(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

RcStyle::RcStyle(GtkRcStyle* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


RcStyle::~RcStyle()
{}


RcStyle::CppClassType RcStyle::rcstyle_class_; // initialize static member

GType RcStyle::get_type()
{
  return rcstyle_class_.init().get_type();
}


GType RcStyle::get_base_type()
{
  return gtk_rc_style_get_type();
}


RcStyle::RcStyle()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(rcstyle_class_.init()))
{
  

}

Glib::RefPtr<RcStyle> RcStyle::create()
{
  return Glib::RefPtr<RcStyle>( new RcStyle() );
}

Glib::RefPtr<RcStyle> RcStyle::copy() const
{
  return Glib::wrap(gtk_rc_style_copy(const_cast<GtkRcStyle*>(gobj())));
}

 Glib::ustring RcStyle::get_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gobj()->name);
}
 
void RcStyle::set_fg(StateType state, const Gdk::Color& color)
{
  gobj()->fg[state] = *color.gobj();
}

Gdk::Color RcStyle::get_fg(StateType state) const
{
  return Gdk::Color(const_cast<GdkColor*>(&gobj()->fg[state]), true);
}

void RcStyle::set_bg(StateType state, const Gdk::Color& color)
{
  gobj()->bg[state] = *color.gobj();
}

Gdk::Color RcStyle::get_bg(StateType state) const
{
  return Gdk::Color(const_cast<GdkColor*>(&gobj()->bg[state]), true);
}

void RcStyle::set_text(StateType state, const Gdk::Color& color)
{
  gobj()->text[state] = *color.gobj();
}

Gdk::Color RcStyle::get_text(StateType state) const
{
  return Gdk::Color(const_cast<GdkColor*>(&gobj()->text[state]), true);
}

void RcStyle::set_base(StateType state, const Gdk::Color& color)
{
  gobj()->base[state] = *color.gobj();
}

Gdk::Color RcStyle::get_base(StateType state) const
{
  return Gdk::Color(const_cast<GdkColor*>(&gobj()->base[state]), true);
}

 int RcStyle::get_xthickness() const
{
  return gobj()->xthickness;
}
 
 int RcStyle::get_ythickness() const
{
  return gobj()->ythickness;
}
 

} // namespace Gtk


