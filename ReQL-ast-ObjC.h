/**
 * @author Adam Grandquist
 */

#import "ReQL-expr-ObjC.h"

@interface libReQL_ast : libReQL_expr

/**
 */
-(instancetype)add;

/**
 */
-(instancetype)all;

/**
 */
-(instancetype)any;

/**
 */
-(instancetype)append;

/**
 */
-(instancetype)april;

/**
 */
-(instancetype)args;

/**
 */
-(instancetype)asc;

/**
 */
-(instancetype)august;

/**
 */
-(instancetype)avg;

/**
 */
-(instancetype)between;

/**
 */
-(instancetype)binary;

/**
 */
-(instancetype)bracket;

/**
 */
-(instancetype)branch;

/**
 */
-(instancetype)changes;

/**
 */
-(instancetype)change_at;

/**
 */
-(instancetype)circle;

/**
 */
-(instancetype)coerce_to;

/**
 */
-(instancetype)concat_map;

/**
 */
-(instancetype)contains;

/**
 */
-(instancetype)count;

/**
 */
-(instancetype)date;

/**
 */
-(instancetype)datum;

/**
 */
-(instancetype)day;

/**
 */
-(instancetype)day_of_week;

/**
 */
-(instancetype)day_of_year;

/**
 */
-(instancetype)db;

/**
 */
-(instancetype)db_create;

/**
 */
-(instancetype)db_drop;

/**
 */
-(instancetype)db_list;

/**
 */
-(instancetype)december;

/**
 */
-(instancetype)default_;

/**
 */
-(instancetype)delete_;

/**
 */
-(instancetype)delete_at;

/**
 */
-(instancetype)desc;

/**
 */
-(instancetype)difference;

/**
 */
-(instancetype)distance;

/**
 */
-(instancetype)distinct;

/**
 */
-(instancetype)div;

/**
 */
-(instancetype)downcase;

/**
 */
-(instancetype)during;

/**
 */
-(instancetype)epoch_time;

/**
 */
-(instancetype)eq;

/**
 */
-(instancetype)eq_join;

/**
 */
-(instancetype)error;

/**
 */
-(instancetype)february;

/**
 */
-(instancetype)fill;

/**
 */
-(instancetype)filter;

/**
 */
-(instancetype)for_each;

/**
 */
-(instancetype)friday;

/**
 */
-(instancetype)func;

/**
 */
-(instancetype)funcall;

/**
 */
-(instancetype)ge;

/**
 */
-(instancetype)geojson;

/**
 */
-(instancetype)get;

/**
 */
-(instancetype)get_all;

/**
 */
-(instancetype)get_field;

/**
 */
-(instancetype)get_intersecting;

/**
 */
-(instancetype)get_nearest;

/**
 */
-(instancetype)group;

/**
 */
-(instancetype)gt;

/**
 */
-(instancetype)has_fields;

/**
 */
-(instancetype)hours;

/**
 */
-(instancetype)http;

/**
 */
-(instancetype)implicit_var;

/**
 */
-(instancetype)includes;

/**
 */
-(instancetype)indexes_of;

/**
 */
-(instancetype)index_create;

/**
 */
-(instancetype)index_drop;

/**
 */
-(instancetype)index_list;

/**
 */
-(instancetype)index_rename;

/**
 */
-(instancetype)index_status;

/**
 */
-(instancetype)index_wait;

/**
 */
-(instancetype)info;

/**
 */
-(instancetype)inner_join;

/**
 */
-(instancetype)insert;

/**
 */
-(instancetype)insert_at;

/**
 */
-(instancetype)intersects;

/**
 */
-(instancetype)in_timezone;

/**
 */
-(instancetype)iso8601;

/**
 */
-(instancetype)is_empty;

/**
 */
-(instancetype)january;

/**
 */
-(instancetype)javascript;

/**
 */
-(instancetype)json;

/**
 */
-(instancetype)july;

/**
 */
-(instancetype)june;

/**
 */
-(instancetype)keys;

/**
 */
-(instancetype)le;

/**
 */
-(instancetype)limit;

/**
 */
-(instancetype)line;

/**
 */
-(instancetype)literal;

/**
 */
-(instancetype)lt;

/**
 */
-(instancetype)make_array;

/**
 */
-(instancetype)make_obj;

/**
 */
-(instancetype)map;

/**
 */
-(instancetype)march;

/**
 */
-(instancetype)match;

/**
 */
-(instancetype)max;

/**
 */
-(instancetype)may;

/**
 */
-(instancetype)merge;

/**
 */
-(instancetype)min;

/**
 */
-(instancetype)minutes;

/**
 */
-(instancetype)mod;

/**
 */
-(instancetype)monday;

/**
 */
-(instancetype)month;

/**
 */
-(instancetype)mul;

/**
 */
-(instancetype)ne;

/**
 */
-(instancetype)not_;

/**
 */
-(instancetype)november;

/**
 */
-(instancetype)now;

/**
 */
-(instancetype)nth;

/**
 */
-(instancetype)object;

/**
 */
-(instancetype)october;

/**
 */
-(instancetype)order_by;

/**
 */
-(instancetype)outer_join;

/**
 */
-(instancetype)pluck;

/**
 */
-(instancetype)point;

/**
 */
-(instancetype)polygon;

/**
 */
-(instancetype)polygon_sub;

/**
 */
-(instancetype)prepend;

/**
 */
-(instancetype)random;

/**
 */
-(instancetype)range;

/**
 */
-(instancetype)reduce;

/**
 */
-(instancetype)replace;

/**
 */
-(instancetype)sample;

/**
 */
-(instancetype)saturday;

/**
 */
-(instancetype)seconds;

/**
 */
-(instancetype)september;

/**
 */
-(instancetype)set_difference;

/**
 */
-(instancetype)set_insert;

/**
 */
-(instancetype)set_intersection;

/**
 */
-(instancetype)set_union;

/**
 */
-(instancetype)skip;

/**
 */
-(instancetype)slice;

/**
 */
-(instancetype)splice_at;

/**
 */
-(instancetype)split;

/**
 */
-(instancetype)sub;

/**
 */
-(instancetype)sum;

/**
 */
-(instancetype)sunday;

/**
 */
-(instancetype)sync;

/**
 */
-(instancetype)table;

/**
 */
-(instancetype)table_create;

/**
 */
-(instancetype)table_drop;

/**
 */
-(instancetype)table_list;

/**
 */
-(instancetype)thursday;

/**
 */
-(instancetype)time;

/**
 */
-(instancetype)timezone;

/**
 */
-(instancetype)time_of_day;

/**
 */
-(instancetype)to_epoch_time;

/**
 */
-(instancetype)to_geojson;

/**
 */
-(instancetype)to_iso8601;

/**
 */
-(instancetype)to_json_string;

/**
 */
-(instancetype)tuesday;

/**
 */
-(instancetype)type_of;

/**
 */
-(instancetype)ungroup;

/**
 */
-(instancetype)union_;

/**
 */
-(instancetype)upcase;

/**
 */
-(instancetype)update;

/**
 */
-(instancetype)uuid;

/**
 */
-(instancetype)var;

/**
 */
-(instancetype)wednesday;

/**
 */
-(instancetype)without;

/**
 */
-(instancetype)with_fields;

/**
 */
-(instancetype)year;

/**
 */
-(instancetype)zip;

@end
