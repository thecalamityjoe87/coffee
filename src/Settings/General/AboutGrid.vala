/*
* Copyright (C) 2017 - Nick Wilkins
*
* Coffee is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* Coffee is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Coffee. If not, see <http://www.gnu.org/licenses/>.
*/
public class Settings.General.AboutGrid : Gtk.Grid {

  private Gtk.Switch _switch_weather;
  private Gtk.Switch _switch_news;

  private Gtk.Button hide_show_key;
  private Gtk.Button close_key;
  private Settings settings;

  public AboutGrid () {
      Object (
          column_spacing: 12,
          halign: Gtk.Align.CENTER,
          row_spacing: 6,
          margin_start: 6,
          margin_end: 6
      );

      settings = Settings.get_default ();

      var hide_show_label = new Gtk.Label("Hide / Show Coffee:") {
          halign = Gtk.Align.END
      };

      var close_label = new Gtk.Label("Quit Coffee:") {
          halign = Gtk.Align.END
      };

      hide_show_key = new Gtk.Button.with_label("F10") {
          sensitive = false,
          halign = Gtk.Align.END
      };

      close_key = new Gtk.Button.with_label("Esc / F4") {
          sensitive = false,
          halign = Gtk.Align.END
      };

      var weather_label = new Gtk.Label("Weather:") {
          halign = Gtk.Align.END
      };
      _switch_weather = new Gtk.Switch ();

      var news_label = new Gtk.Label("News:") {
          halign = Gtk.Align.END
      };
      _switch_news = new Gtk.Switch ();

      if (settings.news_bool)
          _switch_news.active = true;

      if (settings.weather_bool)
          _switch_weather.active = true;

      attach(weather_label, 1, 0);
      attach(_switch_weather, 2, 0);
      attach(news_label, 1, 1);
      attach(_switch_news, 2, 1);
      attach(hide_show_label, 1, 2);
      attach(hide_show_key, 2, 2);
      attach(close_label, 1, 3);
      attach(close_key, 2, 3);

      _switch_weather.notify["active"].connect (() => {
          settings.change_setting_bool(_switch_weather.active, settings.weather_string);
      });
      _switch_news.notify["active"].connect (() => {
          settings.change_setting_bool(_switch_news.active, settings.news_string);
      });

      connect_events ();
  }

  private void connect_events () {
      hide_show_key.clicked.connect (() => {
          hide_show_key.set_label ("Assign New Key ...");
          var key_controller = new Gtk.EventControllerKey ();
          key_controller.key_pressed.connect (key_pressed);
          hide_show_key.add_controller (key_controller);
      });
  }

  private bool key_pressed (Gtk.EventControllerKey controller, uint keyval, uint keycode, Gdk.ModifierType state) {
      hide_show_key.set_label (Gdk.keyval_name (keyval));
      hide_show_key.remove_controller (controller);
      return true;
  }
}

