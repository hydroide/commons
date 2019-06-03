#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SQLS_H
#define SQLS_H

#include <QString>
QString DROPEstn = QString("DROP TABLE IF EXISTS STATION_INFO;");
QString CRTNEstn = QString("CREATE TABLE IF NOT EXISTS STATION_INFO (" // 测站基本信息表
                              "stcd TEXT," // 测站编码
                              "stnm TEXT," // 测站名称
                              "sthd TEXT," // 固定尾部
                              "timestamp DATETIME"
                              ");");
QString DROPEzqr = QString("DROP TABLE IF EXISTS ZQ_PROCESS;");
QString CRTNEzqr = QString("CREATE TABLE IF NOT EXISTS ZQ_PROCESS (" // 水位流量过程表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "row_id INTERGER," // 一个文件中从0开始的序号
                           "month INTEGER," // 月
                           "day INTERGER," // 日
                           "time TEXT,"  // 时间
                              "stage TEXT," // 水位
                              "discharge TEXT," // 流量
                              "annotation TEXT," // 附注
                              "timestamp DATETIME"
                              ");");
QString DROPEzqm = QString("DROP TABLE IF EXISTS ZQ_MEASUREMENT;");
QString CRTNEzqm = QString("CREATE TABLE IF NOT EXISTS ZQ_MEASUREMENT(" // 实测流量表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "record_id INTERGER," // 从0开始的序号
                              "mmsn TEXT," // 流量测次（每站每年一套编号）
                              "month INTERGER," // 月
                              "day INTERGER," // 日
                              "start_time TEXT," // 开始时间
                              "end_time TEXT," // 结束时间
                              "location TEXT," // 断面位置
                              "stage TEXT," // 水位
                              "discharge TEXT," // 流量
                              "area TEXT," // 断面面积
                              "avg_v TEXT," // 平均流速
                              "max_v TEXT," // 最大流速
                              "stream_w TEXT," // 水面宽
                              "avg_depth TEXT," // 平均水深
                              "max_depth TEXT," // 最大水深
                              "surface_slope TEXT," // 水面比降
                              "mannings_n TEXT," // 糙率
                              "annotation TEXT," // 附注
                              "method TEXT," // 流量测法
                              "points TEXT," // 测点数
                              "timestamp DATETIME"
                              ");");
QString DROPEzqp = QString("DROP TABLE IF EXISTS ZQ_PERIOD;");
QString CRTNEzqp = QString("CREATE TABLE IF NOT EXISTS ZQ_PERIOD (" // 推流时段表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "period_id INTERGER," // 时段编号（每站每年一套编号）
                              "start_time TEXT," // 启用时间（含）
                              "end_time TEXT," // 最后一次使用时间（含）
                              "method_id INTERGER," // 方法编号
                              "curve_id INTERGER," // 采用线号
                              "annotation TEXT," // 附注
                              "timestamp DATETIME"
                              ");");
QString DROPEzqcn = QString("DROP TABLE IF EXISTS ZQ_CURVE_NODE;");
QString CRTNEzqcn = QString("CREATE TABLE IF NOT EXISTS ZQ_CURVE_NODE (" // 推流结点表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "curve_id INTERGER," // 线号（每站每年一套编号）
                              "node_id INTERGER," // 结点号（每线一套编号）
                              "stage TEXT," // 水位
                              "discharge TEXT," // 流量
                              "timestamp DATETIME"
                              ");");
QString DROPEscp = QString("DROP TABLE IF EXISTS SQ_PERIOD;");
QString CRTNEscp = QString("CREATE TABLE IF NOT EXISTS SQ_PERIOD (" // 推沙时段表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "period_id INTERGER," // 时段编号（每站每年一套编号）
                              "start_time TEXT," // 启用时间
                              "end_time TEXT," // 最后一次使用时间（含）
                              "method_id INTERGER," // 方法编号
                              "curve_id INTERGER," // 采用线号
                              "annotation TEXT," // 附注
                              "timestamp DATETIME"
                              ");");
QString DROPEsccn = QString("DROP TABLE IF EXISTS SQ_CURVE_NODE;");
QString CRTNEsccn = QString("CREATE TABLE IF NOT EXISTS SQ_CURVE_NODE (" // 推沙结点表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "curve_id INTERGER," // 线号（每站每年一套编号）
                              "node_id INTERGER," // 结点号（每线一套编号）
                              "sssc TEXT," // 单位水样含沙量
                              "csmsc TEXT," // 断面平均含沙量
                              "timestamp DATETIME"
                              ");");
QString DROPEscr = QString("DROP TABLE IF EXISTS SQ_PROCESS;");
QString CRTNEscr = QString("CREATE TABLE IF NOT EXISTS SQ_PROCESS (" // 含沙量过程表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "row_id INTERGER," // 一个文件中从0开始的序号
                           "month INTERGER," // 月
                           "day INTERGER," // 日
                           "time TEXT," // 时间
                              "concentration TEXT," // 含沙量
                              "annotation TEXT,"  // 附注
                              "timestamp DATETIME"
                              ");");
QString DROPEsqm = QString("DROP TABLE IF EXISTS SQ_MEASUREMENT;");
QString CRTNEsqm = QString("CREATE TABLE IF NOT EXISTS SQ_MEASUREMENT(" // 实测输沙率成果表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "record_id INTERGER," // 从0开始的序号
                              "mmsn TEXT," // 输沙率测次（每站每年一套编号）
                              "zqmmsn TEXT," // 流量测次（每站每年一套编号）
                              "month INTERGER," // 月
                              "day INTERGER," // 日
                              "start_time TEXT," // 开始时间
                              "end_time TEXT," // 结束时间
                              "discharge TEXT," // 流量
                              "cssqr TEXT," // 断面输沙率
                              "csmsc TEXT," // 断面平均含沙量
                              "sssc TEXT," // 单位水样含沙量
                              "sssm TEXT," // 单样含沙量测法
                              "annotation TEXT," // 附注
                              "equipmentType TEXT," // 仪器类型
                              "points TEXT," // 测点数
                              "method TEXT," // 输沙率测法
                              "timestamp DATETIME"
                              ");");
QString DROPEcss = QString("DROP TABLE IF EXISTS CS_SURVEY;");
QString CRTNEcss = QString("CREATE TABLE IF NOT EXISTS CS_SURVEY (" // 断面测量表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "survey_id INTERGER," // 测次编号（每站每年一套编号）
                              "month INTERGER," // 月
                              "day INTERGER," // 日
                              "location TEXT," // 断面位置
                              "stage TEXT," // 测时水位
                              "annotation TEXT," // 附注
                              "timestamp DATETIME"
                              ");");
QString DROPEcssv = QString("DROP TABLE IF EXISTS CS_VERTICAL;");
QString CRTNEcssv = QString("CREATE TABLE IF NOT EXISTS CS_VERTICAL(" // 断面垂线表
                              "_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "stcd TEXT," // 测站编码
                              "year INTERGER," // 年份
                              "survey_id INTERGER," // 测次编号（每站每年一套编号）
                              "record_id INTERGER," // 从0开始的序号
                              "vertical_id TEXT," // 垂线编号
                              "distance TEXT," // 起点距
                              "elevation TEXT," // 高程
                              "annotation TEXT," // 附注
                              "timestamp DATETIME"
                              ");");


#endif // SQLS_H
