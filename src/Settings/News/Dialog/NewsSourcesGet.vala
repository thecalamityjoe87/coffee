/*
* Copyright (C) 2018 - Nick Wilkins
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
using Gtk;

namespace Settings {
  public class News.NewsSourceGet : Object {

    private string sources_uri = "https://newsapi.org/v2/sources?";
    //private string sources_uri = "https://newsapi.org/v2/sources?apiKey=2695515e69d14f59baf1236334cdc67f";
    private string besticons_uri = "https://coffee-favicon.herokuapp.com/allicons.json?url=";
    //https://besticon.herokuapp.com/allicons.json?url=
    private NewsSource news_sources;
    private string apiKey = "2695515e69d14f59baf1236334cdc67f";

    construct {
        news_sources = NewsSource.get_default ();
    }

  public async void get_sources(string category = "", string country = "") {
      if (category != "" && country != "") {
          sources_uri = "https://newsapi.org/v2/sources?" + "category=" + category + "&language=" + country + "&apiKey=" + apiKey;
      } else {
          sources_uri = "https://newsapi.org/v2/sources?" + "&apiKey=" + apiKey;
      }

      var session = new Soup.Session();
      session.user_agent = "Coffee/1.0";
      var message = new Soup.Message("GET", sources_uri);
      
      try {
        GLib.Bytes bytes = yield session.send_and_read_async (message, GLib.Priority.HIGH, null);
        debug("(getsources)Parsing message with length: %zu", bytes.get_size());
        parse_message(bytes);
      } catch (Error e) {
          stderr.printf("Error fetching sources: %s\n", e.message);
      }
  }

  private async void parse_message(GLib.Bytes bytes) {
    debug("Parsing message with length: %zu", bytes.get_size());
    var parser = new Json.Parser();
    parser.load_from_data((string) bytes.get_data(), -1);
    var root_object = parser.get_root().get_object();

      try {          
          if (root_object != null){
              print_root(parser.get_root());
              var response = root_object.get_array_member("sources");
              add_sources(response);
          } else {
              stderr.printf("Error: 'sources' array not found in the response.\n");
          }
      } catch (Json.ParserError e) {
          stderr.printf("JSON parsing error: %s\n", e.message);
      } catch (GLib.Error e) {
          stderr.printf("Error occurred while processing the message: %s\n", e.message);
      }
  }


public async string get_besticon_url (string source_name) {
      debug("get_besticon_url(%s)", source_name);
      var uri = besticons_uri + source_name;
      var session = new Soup.Session ();
      string besticon_url = "";
      var message = new Soup.Message ("GET", uri);
      
      try {
        GLib.Bytes bytes = yield session.send_and_read_async (message, GLib.Priority.HIGH, null);
        besticon_url = parse_besticon_message(bytes);
      } catch (Error e) {
          warning ("Besticon: %s", e.message);
      }
  
      return besticon_url;
  }
  
  private string parse_besticon_message (GLib.Bytes bytes) {
      try {
          var parser = new Json.Parser ();
          parser.load_from_data((string) bytes.get_data(), -1);
          var root_object = parser.get_root ().get_object();
          if(root_object.get_array_member ("icons") != null && root_object.get_array_member ("icons").get_length() > 0) {
              var response = root_object.get_array_member ("icons").get_object_element(1);
              return response.get_string_member ("url");
          }
          else {
              return "";
          }
      } catch (Error e) {
          stderr.printf ("I guess something is not working...\n%s", e.message);
          return "";
      }
  }
  

private async void add_sources (Json.Array response){
    int i = 0;
      foreach (var geonode in response.get_elements ()) {
        var geoname = geonode.get_object ();
        var news_source = new NewsSource ();
        news_source.id = geoname.get_string_member ("id");
        news_source.name = geoname.get_string_member ("name");
        news_source.description = geoname.get_string_member ("description");
        news_source.url = geoname.get_string_member ("url");
        news_source.category = geoname.get_string_member ("category");
        news_source.country = geoname.get_string_member ("country");

        //get_besticon_url.begin (news_source.url, (obj, res) => {
          //news_source.besticon_url = yield get_besticon_url (geoname.get_string_member ("url"));
        //});
        //warning (news_source.besticon_url);

        news_sources.add_source (news_source);
        i++;
      }
      news_sources.get_sources_completed ();
    }
  }
}

/*private void print_root (Json.Node root) {
    Json.Generator generator = new Json.Generator ();
    generator.set_root (root);
    debug (generator.to_data (null) + "\n");
}*/