#ifndef FLIGHTTASK_H
#define FLIGHTTASK_H

#include <QtGlobal>
#include <QString>
#include <QVariant>
#include <QVector>

template<typename T>
struct FieldValue
{
    QString key;
    QString text;
    T value = {};
    bool visible = true;

    QVariant toVariant() const
    {
        return QVariant::fromValue(value);
    }
};

struct Waypoint
{
    FieldValue<bool> sea = {"sea", "Море", false};
    FieldValue<bool> tm_long = {"tm_long", "Дальня ТМ вимкнена", false};
    FieldValue<bool> tm_short = {"tm_short", "Ближня ТМ вимкнена", false};
    FieldValue<bool> terrain = {"terrain", "Режим огинання рельєфу", false};
    FieldValue<bool> barometric = {"barometric", "Коригування по БВ", false};
    FieldValue<bool> gnss = {"gnss", "Коригування по GNSS", false};
    FieldValue<bool> traj_control = {"traj_control", "Траєкторне керування", false};
    FieldValue<bool> course_control = {"course_control", "Курсове керування без GNSS", false};

    FieldValue<quint8> reserve_u8 = {"reserve_u8", "Резерв", 0, false};
    FieldValue<quint16> reserve_u16 = {"reserve_u16", "Резерв", 0, false};
    FieldValue<float> reserve_float = {"reserve_float", "Резерв", 0.0f, false};

    FieldValue<float> engine_speed = {"engine_speed", "Швидкість МД, %", 0.0f};
    FieldValue<float> altitude = {"altitude", "Висота WGS-84, m", 0.0f};
    FieldValue<double> latitude = {"latitude", "Широта WGS-84, deg", 0.0};
    FieldValue<double> longitude = {"longitude", "Довгота WGS-84, deg", 0.0};
};

struct Mission
{
    FieldValue<qint64> id = {"id", "ID місії", -1};
    FieldValue<QString> name = {"name", "Назва місії", QString()};

    FieldValue<quint32> task_number = {"task_number", "Унікальний номер ПЗ", 0};
    FieldValue<quint16> point_count = {"point_count", "Кількість навігаційних точок, N", 0};

    FieldValue<quint16> detach_time = {"detach_time", "Час команди «Отдел», s", 0};
    FieldValue<quint16> start_time = {"start_time", "Час команди «Ст», s", 0};
    FieldValue<quint16> engine_time = {"engine_time", "Час команди «МД», s", 0};
    FieldValue<quint16> self_destruct_time = {"self_destruct_time", "Час команди «СЛ», s", 0};

    FieldValue<float> target_altitude = {"target_altitude", "Висота цілі, m", 0.0f};
    FieldValue<float> correction_altitude = {"correction_altitude", "Висота коригування, m", 0.0f};
    FieldValue<float> attack_range = {"attack_range", "Дальність атаки цілі, m", 0.0f};
    FieldValue<float> reserve_float = {"reserve_float", "Резерв", 0.0f, false};

    QVector<Waypoint> points;
};

struct GroupMission
{
    QVector<Mission> missions;
};

#endif // FLIGHTTASK_H
