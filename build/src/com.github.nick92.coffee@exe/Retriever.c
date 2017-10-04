/* Retriever.c generated by valac 0.30.1, the Vala compiler
 * generated from Retriever.vala, do not modify */

/*
 * Retriever.vala
 * This file is part of Coffee
 *
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

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <gee.h>
#include <libsoup/soup.h>


#define WORKER_TYPE_RETRIEVER (worker_retriever_get_type ())
#define WORKER_RETRIEVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), WORKER_TYPE_RETRIEVER, WorkerRetriever))
#define WORKER_RETRIEVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), WORKER_TYPE_RETRIEVER, WorkerRetrieverClass))
#define WORKER_IS_RETRIEVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), WORKER_TYPE_RETRIEVER))
#define WORKER_IS_RETRIEVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), WORKER_TYPE_RETRIEVER))
#define WORKER_RETRIEVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), WORKER_TYPE_RETRIEVER, WorkerRetrieverClass))

typedef struct _WorkerRetriever WorkerRetriever;
typedef struct _WorkerRetrieverClass WorkerRetrieverClass;
typedef struct _WorkerRetrieverPrivate WorkerRetrieverPrivate;

#define WORKER_TYPE_PARSER (worker_parser_get_type ())
#define WORKER_PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), WORKER_TYPE_PARSER, WorkerParser))
#define WORKER_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), WORKER_TYPE_PARSER, WorkerParserClass))
#define WORKER_IS_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), WORKER_TYPE_PARSER))
#define WORKER_IS_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), WORKER_TYPE_PARSER))
#define WORKER_PARSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), WORKER_TYPE_PARSER, WorkerParserClass))

typedef struct _WorkerParser WorkerParser;
typedef struct _WorkerParserClass WorkerParserClass;

#define SETTINGS_TYPE_SETTINGS (settings_settings_get_type ())
#define SETTINGS_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SETTINGS_TYPE_SETTINGS, SettingsSettings))
#define SETTINGS_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SETTINGS_TYPE_SETTINGS, SettingsSettingsClass))
#define SETTINGS_IS_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SETTINGS_TYPE_SETTINGS))
#define SETTINGS_IS_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SETTINGS_TYPE_SETTINGS))
#define SETTINGS_SETTINGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SETTINGS_TYPE_SETTINGS, SettingsSettingsClass))

typedef struct _SettingsSettings SettingsSettings;
typedef struct _SettingsSettingsClass SettingsSettingsClass;

#define COFFEE_TYPE_POST (coffee_post_get_type ())
#define COFFEE_POST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), COFFEE_TYPE_POST, CoffeePost))
#define COFFEE_POST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), COFFEE_TYPE_POST, CoffeePostClass))
#define COFFEE_IS_POST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), COFFEE_TYPE_POST))
#define COFFEE_IS_POST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), COFFEE_TYPE_POST))
#define COFFEE_POST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), COFFEE_TYPE_POST, CoffeePostClass))

typedef struct _CoffeePost CoffeePost;
typedef struct _CoffeePostClass CoffeePostClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _WorkerRetrieverRunParserNewsData WorkerRetrieverRunParserNewsData;
typedef struct _WorkerRetrieverRunParserWeatherData WorkerRetrieverRunParserWeatherData;

struct _WorkerRetriever {
	GObject parent_instance;
	WorkerRetrieverPrivate * priv;
	GSourceFunc callback;
	gpointer callback_target;
	GDestroyNotify callback_target_destroy_notify;
};

struct _WorkerRetrieverClass {
	GObjectClass parent_class;
};

struct _WorkerRetrieverPrivate {
	WorkerParser* parser;
	SettingsSettings* settings;
	CoffeePost* post;
	gchar* apiKey;
	gchar* geolocation;
};

struct _WorkerRetrieverRunParserNewsData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	WorkerRetriever* self;
	GeeArrayList* _source_list;
	SettingsSettings* _tmp0_;
	GeeArrayList* _tmp1_;
	gint _source_size;
	GeeArrayList* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	gint _source_index;
	gint _tmp5_;
	gint _tmp6_;
	gint _tmp7_;
	gchar* source;
	GeeArrayList* _tmp8_;
	gint _tmp9_;
	gpointer _tmp10_;
	const gchar* _tmp11_;
	CoffeePost* _tmp12_;
	CoffeePost* _tmp13_;
};

struct _WorkerRetrieverRunParserWeatherData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	WorkerRetriever* self;
	SettingsSettings* _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp2_;
	SettingsSettings* _tmp3_;
	const gchar* _tmp4_;
	const gchar* _tmp5_;
	gchar* _tmp6_;
	const gchar* _tmp7_;
	SettingsSettings* _tmp8_;
	gboolean _tmp9_;
	gboolean _tmp10_;
	SettingsSettings* _tmp11_;
	gboolean _tmp12_;
	gboolean _tmp13_;
};


static gpointer worker_retriever_parent_class = NULL;

GType worker_retriever_get_type (void) G_GNUC_CONST;
GType worker_parser_get_type (void) G_GNUC_CONST;
GType settings_settings_get_type (void) G_GNUC_CONST;
GType coffee_post_get_type (void) G_GNUC_CONST;
#define WORKER_RETRIEVER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), WORKER_TYPE_RETRIEVER, WorkerRetrieverPrivate))
enum  {
	WORKER_RETRIEVER_DUMMY_PROPERTY
};
WorkerRetriever* worker_retriever_new (void);
WorkerRetriever* worker_retriever_construct (GType object_type);
SettingsSettings* settings_settings_get_default (void);
CoffeePost* coffee_post_get_default (void);
static void worker_retriever_run_parser_news_data_free (gpointer _data);
void worker_retriever_run_parser_news (WorkerRetriever* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void worker_retriever_run_parser_news_finish (WorkerRetriever* self, GAsyncResult* _res_);
static gboolean worker_retriever_run_parser_news_co (WorkerRetrieverRunParserNewsData* _data_);
static gboolean _worker_retriever_run_parser_news_co_gsource_func (gpointer self);
GeeArrayList* settings_settings_get_news_sources_random (SettingsSettings* self);
static void worker_retriever_parse_message (WorkerRetriever* self, const gchar* source);
void coffee_post_parse_completed (CoffeePost* self);
static void worker_retriever_run_parser_weather_data_free (gpointer _data);
void worker_retriever_run_parser_weather (WorkerRetriever* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void worker_retriever_run_parser_weather_finish (WorkerRetriever* self, GAsyncResult* _res_);
static gboolean worker_retriever_run_parser_weather_co (WorkerRetrieverRunParserWeatherData* _data_);
static gboolean _worker_retriever_run_parser_weather_co_gsource_func (gpointer self);
gboolean settings_settings_get_weather_bool (SettingsSettings* self);
const gchar* settings_settings_get_geo_location_string (SettingsSettings* self);
gboolean settings_settings_get_dark_sky_bool (SettingsSettings* self);
#define WORKER_SOURCES_DARK_SKY "dark-sky"
gboolean settings_settings_get_open_weather_bool (SettingsSettings* self);
#define WORKER_SOURCES_OPEN_WEATHER_MAP "open-weather-map"
gchar* worker_retriever_get_source_from_uri (WorkerRetriever* self, const gchar* news_source);
WorkerParser* worker_parser_new (void);
WorkerParser* worker_parser_construct (GType object_type);
void worker_parser_parse_message (WorkerParser* self, SoupMessage* message, const gchar* source);
static void worker_retriever_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


WorkerRetriever* worker_retriever_construct (GType object_type) {
	WorkerRetriever * self = NULL;
	SettingsSettings* _tmp0_ = NULL;
	CoffeePost* _tmp1_ = NULL;
#line 33 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self = (WorkerRetriever*) g_object_new (object_type, NULL);
#line 34 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp0_ = settings_settings_get_default ();
#line 34 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (self->priv->settings);
#line 34 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->priv->settings = _tmp0_;
#line 35 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp1_ = coffee_post_get_default ();
#line 35 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (self->priv->post);
#line 35 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->priv->post = _tmp1_;
#line 33 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	return self;
#line 211 "Retriever.c"
}


WorkerRetriever* worker_retriever_new (void) {
#line 33 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	return worker_retriever_construct (WORKER_TYPE_RETRIEVER);
#line 218 "Retriever.c"
}


static void worker_retriever_run_parser_news_data_free (gpointer _data) {
	WorkerRetrieverRunParserNewsData* _data_;
	_data_ = _data;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (_data_->self);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_slice_free (WorkerRetrieverRunParserNewsData, _data_);
#line 229 "Retriever.c"
}


static gpointer _g_object_ref0 (gpointer self) {
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	return self ? g_object_ref (self) : NULL;
#line 236 "Retriever.c"
}


void worker_retriever_run_parser_news (WorkerRetriever* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	WorkerRetrieverRunParserNewsData* _data_;
	WorkerRetriever* _tmp0_ = NULL;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_ = g_slice_new0 (WorkerRetrieverRunParserNewsData);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, worker_retriever_run_parser_news);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, worker_retriever_run_parser_news_data_free);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp0_ = _g_object_ref0 (self);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->self = _tmp0_;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	worker_retriever_run_parser_news_co (_data_);
#line 255 "Retriever.c"
}


void worker_retriever_run_parser_news_finish (WorkerRetriever* self, GAsyncResult* _res_) {
	WorkerRetrieverRunParserNewsData* _data_;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
#line 263 "Retriever.c"
}


static gboolean _worker_retriever_run_parser_news_co_gsource_func (gpointer self) {
	gboolean result;
	result = worker_retriever_run_parser_news_co (self);
#line 40 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	return result;
#line 272 "Retriever.c"
}


static gboolean worker_retriever_run_parser_news_co (WorkerRetrieverRunParserNewsData* _data_) {
#line 38 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	switch (_data_->_state_) {
#line 38 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		case 0:
#line 281 "Retriever.c"
		goto _state_0;
#line 38 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		case 1:
#line 285 "Retriever.c"
		goto _state_1;
		default:
#line 38 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		g_assert_not_reached ();
#line 290 "Retriever.c"
	}
	_state_0:
#line 40 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _worker_retriever_run_parser_news_co_gsource_func, _data_, NULL);
#line 295 "Retriever.c"
	{
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp0_ = NULL;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp0_ = _data_->self->priv->settings;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp1_ = NULL;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp1_ = settings_settings_get_news_sources_random (_data_->_tmp0_);
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_source_list = _data_->_tmp1_;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp2_ = NULL;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp2_ = _data_->_source_list;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp3_ = 0;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp3_ = gee_abstract_collection_get_size ((GeeCollection*) _data_->_tmp2_);
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp4_ = 0;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp4_ = _data_->_tmp3_;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_source_size = _data_->_tmp4_;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_source_index = -1;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		while (TRUE) {
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp5_ = 0;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp5_ = _data_->_source_index;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_source_index = _data_->_tmp5_ + 1;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp6_ = 0;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp6_ = _data_->_source_index;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp7_ = 0;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp7_ = _data_->_source_size;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			if (!(_data_->_tmp6_ < _data_->_tmp7_)) {
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
				break;
#line 343 "Retriever.c"
			}
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp8_ = NULL;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp8_ = _data_->_source_list;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp9_ = 0;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp9_ = _data_->_source_index;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp10_ = NULL;
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp10_ = gee_abstract_list_get ((GeeAbstractList*) _data_->_tmp8_, _data_->_tmp9_);
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->source = (gchar*) _data_->_tmp10_;
#line 42 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp11_ = NULL;
#line 42 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp11_ = _data_->source;
#line 42 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			worker_retriever_parse_message (_data_->self, _data_->_tmp11_);
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_g_free0 (_data_->source);
#line 367 "Retriever.c"
		}
#line 41 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_g_object_unref0 (_data_->_source_list);
#line 371 "Retriever.c"
	}
#line 45 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_tmp12_ = NULL;
#line 45 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_tmp12_ = _data_->self->priv->post;
#line 45 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	if (_data_->_tmp12_ != NULL) {
#line 46 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp13_ = NULL;
#line 46 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp13_ = _data_->self->priv->post;
#line 46 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		coffee_post_parse_completed (_data_->_tmp13_);
#line 385 "Retriever.c"
	}
#line 49 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_state_ = 1;
#line 49 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	return FALSE;
#line 391 "Retriever.c"
	_state_1:
	;
#line 38 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	if (_data_->_state_ == 0) {
#line 38 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		g_simple_async_result_complete_in_idle (_data_->_async_result);
#line 398 "Retriever.c"
	} else {
#line 38 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		g_simple_async_result_complete (_data_->_async_result);
#line 402 "Retriever.c"
	}
#line 38 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_object_unref (_data_->_async_result);
#line 38 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	return FALSE;
#line 408 "Retriever.c"
}


static void worker_retriever_run_parser_weather_data_free (gpointer _data) {
	WorkerRetrieverRunParserWeatherData* _data_;
	_data_ = _data;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (_data_->self);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_slice_free (WorkerRetrieverRunParserWeatherData, _data_);
#line 419 "Retriever.c"
}


void worker_retriever_run_parser_weather (WorkerRetriever* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	WorkerRetrieverRunParserWeatherData* _data_;
	WorkerRetriever* _tmp0_ = NULL;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_ = g_slice_new0 (WorkerRetrieverRunParserWeatherData);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, worker_retriever_run_parser_weather);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, worker_retriever_run_parser_weather_data_free);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp0_ = _g_object_ref0 (self);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->self = _tmp0_;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	worker_retriever_run_parser_weather_co (_data_);
#line 438 "Retriever.c"
}


void worker_retriever_run_parser_weather_finish (WorkerRetriever* self, GAsyncResult* _res_) {
	WorkerRetrieverRunParserWeatherData* _data_;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
#line 446 "Retriever.c"
}


static gboolean _worker_retriever_run_parser_weather_co_gsource_func (gpointer self) {
	gboolean result;
	result = worker_retriever_run_parser_weather_co (self);
#line 53 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	return result;
#line 455 "Retriever.c"
}


static gboolean worker_retriever_run_parser_weather_co (WorkerRetrieverRunParserWeatherData* _data_) {
#line 52 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	switch (_data_->_state_) {
#line 52 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		case 0:
#line 464 "Retriever.c"
		goto _state_0;
#line 52 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		case 1:
#line 468 "Retriever.c"
		goto _state_1;
		default:
#line 52 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		g_assert_not_reached ();
#line 473 "Retriever.c"
	}
	_state_0:
#line 53 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _worker_retriever_run_parser_weather_co_gsource_func, _data_, NULL);
#line 55 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_tmp0_ = NULL;
#line 55 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_tmp0_ = _data_->self->priv->settings;
#line 55 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_tmp1_ = FALSE;
#line 55 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_tmp1_ = settings_settings_get_weather_bool (_data_->_tmp0_);
#line 55 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_tmp2_ = FALSE;
#line 55 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_tmp2_ = _data_->_tmp1_;
#line 55 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	if (_data_->_tmp2_) {
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp3_ = NULL;
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp3_ = _data_->self->priv->settings;
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp4_ = NULL;
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp4_ = settings_settings_get_geo_location_string (_data_->_tmp3_);
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp5_ = NULL;
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp5_ = _data_->_tmp4_;
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp6_ = NULL;
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp6_ = g_strdup (_data_->_tmp5_);
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_g_free0 (_data_->self->priv->geolocation);
#line 56 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->self->priv->geolocation = _data_->_tmp6_;
#line 57 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp7_ = NULL;
#line 57 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_data_->_tmp7_ = _data_->self->priv->geolocation;
#line 57 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		if (g_strcmp0 (_data_->_tmp7_, "") != 0) {
#line 59 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp8_ = NULL;
#line 59 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp8_ = _data_->self->priv->settings;
#line 59 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp9_ = FALSE;
#line 59 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp9_ = settings_settings_get_dark_sky_bool (_data_->_tmp8_);
#line 59 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp10_ = FALSE;
#line 59 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp10_ = _data_->_tmp9_;
#line 59 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			if (_data_->_tmp10_) {
#line 60 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
				worker_retriever_parse_message (_data_->self, WORKER_SOURCES_DARK_SKY);
#line 534 "Retriever.c"
			}
#line 62 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp11_ = NULL;
#line 62 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp11_ = _data_->self->priv->settings;
#line 62 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp12_ = FALSE;
#line 62 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp12_ = settings_settings_get_open_weather_bool (_data_->_tmp11_);
#line 62 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp13_ = FALSE;
#line 62 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_data_->_tmp13_ = _data_->_tmp12_;
#line 62 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			if (_data_->_tmp13_) {
#line 63 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
				worker_retriever_parse_message (_data_->self, WORKER_SOURCES_OPEN_WEATHER_MAP);
#line 552 "Retriever.c"
			}
		}
	}
#line 66 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_data_->_state_ = 1;
#line 66 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	return FALSE;
#line 560 "Retriever.c"
	_state_1:
	;
#line 52 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	if (_data_->_state_ == 0) {
#line 52 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		g_simple_async_result_complete_in_idle (_data_->_async_result);
#line 567 "Retriever.c"
	} else {
#line 52 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		g_simple_async_result_complete (_data_->_async_result);
#line 571 "Retriever.c"
	}
#line 52 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_object_unref (_data_->_async_result);
#line 52 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	return FALSE;
#line 577 "Retriever.c"
}


static void worker_retriever_parse_message (WorkerRetriever* self, const gchar* source) {
	gchar* uri = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	SoupSession* session = NULL;
	SoupSession* _tmp2_ = NULL;
	SoupMessage* message = NULL;
	SoupMessage* _tmp3_ = NULL;
	WorkerParser* _tmp4_ = NULL;
	WorkerParser* _tmp5_ = NULL;
	const gchar* _tmp6_ = NULL;
#line 69 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_return_if_fail (self != NULL);
#line 69 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_return_if_fail (source != NULL);
#line 70 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp0_ = source;
#line 70 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp1_ = worker_retriever_get_source_from_uri (self, _tmp0_);
#line 70 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	uri = _tmp1_;
#line 71 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp2_ = soup_session_new ();
#line 71 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	session = _tmp2_;
#line 72 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp3_ = soup_message_new ("GET", uri);
#line 72 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	message = _tmp3_;
#line 73 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	soup_session_send_message (session, message);
#line 75 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp4_ = worker_parser_new ();
#line 75 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (self->priv->parser);
#line 75 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->priv->parser = _tmp4_;
#line 76 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp5_ = self->priv->parser;
#line 76 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp6_ = source;
#line 76 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	worker_parser_parse_message (_tmp5_, message, _tmp6_);
#line 69 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (message);
#line 69 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (session);
#line 69 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_free0 (uri);
#line 630 "Retriever.c"
}


gchar* worker_retriever_get_source_from_uri (WorkerRetriever* self, const gchar* news_source) {
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
#line 79 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 79 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_return_val_if_fail (news_source != NULL, NULL);
#line 81 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp0_ = news_source;
#line 81 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	if (g_strcmp0 (_tmp0_, WORKER_SOURCES_DARK_SKY) == 0) {
#line 645 "Retriever.c"
		const gchar* _tmp1_ = NULL;
		gchar* _tmp2_ = NULL;
		gchar* _tmp3_ = NULL;
		gchar* _tmp4_ = NULL;
		gchar* _tmp5_ = NULL;
#line 82 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_tmp1_ = self->priv->geolocation;
#line 82 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_tmp2_ = g_strconcat ("https://api.darksky.net/forecast/06446ae7099feacb17ffef78fdf89f0a/", _tmp1_, NULL);
#line 82 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_tmp3_ = _tmp2_;
#line 82 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_tmp4_ = g_strconcat (_tmp3_, "?units=auto&exclude=[minutely,alerts,flags]", NULL);
#line 82 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_tmp5_ = _tmp4_;
#line 82 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_g_free0 (_tmp3_);
#line 82 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		result = _tmp5_;
#line 82 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		return result;
#line 667 "Retriever.c"
	} else {
		const gchar* _tmp6_ = NULL;
#line 83 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		_tmp6_ = news_source;
#line 83 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
		if (g_strcmp0 (_tmp6_, WORKER_SOURCES_OPEN_WEATHER_MAP) == 0) {
#line 674 "Retriever.c"
			const gchar* _tmp7_ = NULL;
			gchar** _tmp8_ = NULL;
			gchar** _tmp9_ = NULL;
			gchar** _tmp10_ = NULL;
			gint _tmp10__length1 = 0;
			const gchar* _tmp11_ = NULL;
			gchar* _tmp12_ = NULL;
			gchar* _tmp13_ = NULL;
			gchar* _tmp14_ = NULL;
			gchar* _tmp15_ = NULL;
			const gchar* _tmp16_ = NULL;
			gchar** _tmp17_ = NULL;
			gchar** _tmp18_ = NULL;
			gchar** _tmp19_ = NULL;
			gint _tmp19__length1 = 0;
			const gchar* _tmp20_ = NULL;
			gchar* _tmp21_ = NULL;
			gchar* _tmp22_ = NULL;
			gchar* _tmp23_ = NULL;
			gchar* _tmp24_ = NULL;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp7_ = self->priv->geolocation;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp9_ = _tmp8_ = g_strsplit (_tmp7_, ",", 0);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp10_ = _tmp9_;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp10__length1 = _vala_array_length (_tmp8_);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp11_ = _tmp10_[0];
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp12_ = g_strconcat ("http://api.openweathermap.org/data/2.5/weather?lat=", _tmp11_, NULL);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp13_ = _tmp12_;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp14_ = g_strconcat (_tmp13_, "&lon=", NULL);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp15_ = _tmp14_;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp16_ = self->priv->geolocation;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp18_ = _tmp17_ = g_strsplit (_tmp16_, ",", 0);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp19_ = _tmp18_;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp19__length1 = _vala_array_length (_tmp17_);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp20_ = _tmp19_[1];
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp21_ = g_strconcat (_tmp15_, _tmp20_, NULL);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp22_ = _tmp21_;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp23_ = g_strconcat (_tmp22_, "&appid=fa2392a571d54a9d17b1f0f0c934d562&units=metric", NULL);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp24_ = _tmp23_;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_g_free0 (_tmp22_);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp19_ = (_vala_array_free (_tmp19_, _tmp19__length1, (GDestroyNotify) g_free), NULL);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_g_free0 (_tmp15_);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_g_free0 (_tmp13_);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp10_ = (_vala_array_free (_tmp10_, _tmp10__length1, (GDestroyNotify) g_free), NULL);
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			result = _tmp24_;
#line 84 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			return result;
#line 745 "Retriever.c"
		} else {
			const gchar* _tmp25_ = NULL;
			gchar* _tmp26_ = NULL;
			gchar* _tmp27_ = NULL;
			gchar* _tmp28_ = NULL;
			gchar* _tmp29_ = NULL;
			const gchar* _tmp30_ = NULL;
			gchar* _tmp31_ = NULL;
			gchar* _tmp32_ = NULL;
			gchar* _tmp33_ = NULL;
			gchar* _tmp34_ = NULL;
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp25_ = news_source;
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp26_ = g_strconcat ("https://newsapi.org/v1/articles?source=", _tmp25_, NULL);
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp27_ = _tmp26_;
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp28_ = g_strconcat (_tmp27_, "&apiKey=", NULL);
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp29_ = _tmp28_;
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp30_ = self->priv->apiKey;
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp31_ = g_strconcat (_tmp29_, _tmp30_, NULL);
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp32_ = _tmp31_;
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp33_ = g_strconcat (_tmp32_, "", NULL);
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_tmp34_ = _tmp33_;
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_g_free0 (_tmp32_);
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_g_free0 (_tmp29_);
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			_g_free0 (_tmp27_);
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			result = _tmp34_;
#line 87 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
			return result;
#line 787 "Retriever.c"
		}
	}
}


static void worker_retriever_class_init (WorkerRetrieverClass * klass) {
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	worker_retriever_parent_class = g_type_class_peek_parent (klass);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	g_type_class_add_private (klass, sizeof (WorkerRetrieverPrivate));
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	G_OBJECT_CLASS (klass)->finalize = worker_retriever_finalize;
#line 800 "Retriever.c"
}


static void worker_retriever_instance_init (WorkerRetriever * self) {
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->priv = WORKER_RETRIEVER_GET_PRIVATE (self);
#line 25 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->priv->parser = NULL;
#line 27 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->priv->post = NULL;
#line 30 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp0_ = g_strdup ("e8a66b24da89420b9a419849e95d47a1");
#line 30 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->priv->apiKey = _tmp0_;
#line 31 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_tmp1_ = g_strdup ("");
#line 31 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->priv->geolocation = _tmp1_;
#line 821 "Retriever.c"
}


static void worker_retriever_finalize (GObject* obj) {
	WorkerRetriever * self;
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, WORKER_TYPE_RETRIEVER, WorkerRetriever);
#line 25 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (self->priv->parser);
#line 26 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (self->priv->settings);
#line 27 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_object_unref0 (self->priv->post);
#line 28 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	(self->callback_target_destroy_notify == NULL) ? NULL : (self->callback_target_destroy_notify (self->callback_target), NULL);
#line 28 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->callback = NULL;
#line 28 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->callback_target = NULL;
#line 28 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	self->callback_target_destroy_notify = NULL;
#line 30 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_free0 (self->priv->apiKey);
#line 31 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	_g_free0 (self->priv->geolocation);
#line 23 "/home/nick/work/Coffee/sample/git/src/Worker/Retriever.vala"
	G_OBJECT_CLASS (worker_retriever_parent_class)->finalize (obj);
#line 849 "Retriever.c"
}


GType worker_retriever_get_type (void) {
	static volatile gsize worker_retriever_type_id__volatile = 0;
	if (g_once_init_enter (&worker_retriever_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (WorkerRetrieverClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) worker_retriever_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (WorkerRetriever), 0, (GInstanceInitFunc) worker_retriever_instance_init, NULL };
		GType worker_retriever_type_id;
		worker_retriever_type_id = g_type_register_static (G_TYPE_OBJECT, "WorkerRetriever", &g_define_type_info, 0);
		g_once_init_leave (&worker_retriever_type_id__volatile, worker_retriever_type_id);
	}
	return worker_retriever_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



