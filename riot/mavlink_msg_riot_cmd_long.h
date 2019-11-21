#pragma once
// MESSAGE RIOT_CMD_LONG PACKING

#define MAVLINK_MSG_ID_RIOT_CMD_LONG 1001

MAVPACKED(
typedef struct __mavlink_riot_cmd_long_t {
 uint8_t target_system; /*<  System ID of target system this message is for.*/
 uint8_t target_component; /*<  Component ID of target Rapid IoT this message is for.*/
 uint8_t cmd_id; /*<  RIOT Long Command ID.*/
 uint8_t data[44]; /*<  RIOT Command related data such as an A100x Challenge value.*/
}) mavlink_riot_cmd_long_t;

#define MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN 47
#define MAVLINK_MSG_ID_RIOT_CMD_LONG_MIN_LEN 47
#define MAVLINK_MSG_ID_1001_LEN 47
#define MAVLINK_MSG_ID_1001_MIN_LEN 47

#define MAVLINK_MSG_ID_RIOT_CMD_LONG_CRC 14
#define MAVLINK_MSG_ID_1001_CRC 14

#define MAVLINK_MSG_RIOT_CMD_LONG_FIELD_DATA_LEN 44

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RIOT_CMD_LONG { \
    1001, \
    "RIOT_CMD_LONG", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_riot_cmd_long_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_riot_cmd_long_t, target_component) }, \
         { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_riot_cmd_long_t, cmd_id) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 44, 3, offsetof(mavlink_riot_cmd_long_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RIOT_CMD_LONG { \
    "RIOT_CMD_LONG", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_riot_cmd_long_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_riot_cmd_long_t, target_component) }, \
         { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_riot_cmd_long_t, cmd_id) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 44, 3, offsetof(mavlink_riot_cmd_long_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a riot_cmd_long message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID of target system this message is for.
 * @param target_component  Component ID of target Rapid IoT this message is for.
 * @param cmd_id  RIOT Long Command ID.
 * @param data  RIOT Command related data such as an A100x Challenge value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_riot_cmd_long_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t cmd_id, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, cmd_id);
    _mav_put_uint8_t_array(buf, 3, data, 44);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN);
#else
    mavlink_riot_cmd_long_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.cmd_id = cmd_id;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*44);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RIOT_CMD_LONG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RIOT_CMD_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_CRC);
}

/**
 * @brief Pack a riot_cmd_long message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID of target system this message is for.
 * @param target_component  Component ID of target Rapid IoT this message is for.
 * @param cmd_id  RIOT Long Command ID.
 * @param data  RIOT Command related data such as an A100x Challenge value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_riot_cmd_long_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t cmd_id,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, cmd_id);
    _mav_put_uint8_t_array(buf, 3, data, 44);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN);
#else
    mavlink_riot_cmd_long_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.cmd_id = cmd_id;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*44);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RIOT_CMD_LONG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RIOT_CMD_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_CRC);
}

/**
 * @brief Encode a riot_cmd_long struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param riot_cmd_long C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_riot_cmd_long_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_riot_cmd_long_t* riot_cmd_long)
{
    return mavlink_msg_riot_cmd_long_pack(system_id, component_id, msg, riot_cmd_long->target_system, riot_cmd_long->target_component, riot_cmd_long->cmd_id, riot_cmd_long->data);
}

/**
 * @brief Encode a riot_cmd_long struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param riot_cmd_long C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_riot_cmd_long_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_riot_cmd_long_t* riot_cmd_long)
{
    return mavlink_msg_riot_cmd_long_pack_chan(system_id, component_id, chan, msg, riot_cmd_long->target_system, riot_cmd_long->target_component, riot_cmd_long->cmd_id, riot_cmd_long->data);
}

/**
 * @brief Send a riot_cmd_long message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID of target system this message is for.
 * @param target_component  Component ID of target Rapid IoT this message is for.
 * @param cmd_id  RIOT Long Command ID.
 * @param data  RIOT Command related data such as an A100x Challenge value.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_riot_cmd_long_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t cmd_id, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, cmd_id);
    _mav_put_uint8_t_array(buf, 3, data, 44);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD_LONG, buf, MAVLINK_MSG_ID_RIOT_CMD_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_CRC);
#else
    mavlink_riot_cmd_long_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.cmd_id = cmd_id;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*44);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD_LONG, (const char *)&packet, MAVLINK_MSG_ID_RIOT_CMD_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_CRC);
#endif
}

/**
 * @brief Send a riot_cmd_long message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_riot_cmd_long_send_struct(mavlink_channel_t chan, const mavlink_riot_cmd_long_t* riot_cmd_long)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_riot_cmd_long_send(chan, riot_cmd_long->target_system, riot_cmd_long->target_component, riot_cmd_long->cmd_id, riot_cmd_long->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD_LONG, (const char *)riot_cmd_long, MAVLINK_MSG_ID_RIOT_CMD_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_CRC);
#endif
}

#if MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_riot_cmd_long_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t cmd_id, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, cmd_id);
    _mav_put_uint8_t_array(buf, 3, data, 44);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD_LONG, buf, MAVLINK_MSG_ID_RIOT_CMD_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_CRC);
#else
    mavlink_riot_cmd_long_t *packet = (mavlink_riot_cmd_long_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->cmd_id = cmd_id;
    mav_array_memcpy(packet->data, data, sizeof(uint8_t)*44);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD_LONG, (const char *)packet, MAVLINK_MSG_ID_RIOT_CMD_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN, MAVLINK_MSG_ID_RIOT_CMD_LONG_CRC);
#endif
}
#endif

#endif

// MESSAGE RIOT_CMD_LONG UNPACKING


/**
 * @brief Get field target_system from riot_cmd_long message
 *
 * @return  System ID of target system this message is for.
 */
static inline uint8_t mavlink_msg_riot_cmd_long_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from riot_cmd_long message
 *
 * @return  Component ID of target Rapid IoT this message is for.
 */
static inline uint8_t mavlink_msg_riot_cmd_long_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field cmd_id from riot_cmd_long message
 *
 * @return  RIOT Long Command ID.
 */
static inline uint8_t mavlink_msg_riot_cmd_long_get_cmd_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field data from riot_cmd_long message
 *
 * @return  RIOT Command related data such as an A100x Challenge value.
 */
static inline uint16_t mavlink_msg_riot_cmd_long_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 44,  3);
}

/**
 * @brief Decode a riot_cmd_long message into a struct
 *
 * @param msg The message to decode
 * @param riot_cmd_long C-struct to decode the message contents into
 */
static inline void mavlink_msg_riot_cmd_long_decode(const mavlink_message_t* msg, mavlink_riot_cmd_long_t* riot_cmd_long)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    riot_cmd_long->target_system = mavlink_msg_riot_cmd_long_get_target_system(msg);
    riot_cmd_long->target_component = mavlink_msg_riot_cmd_long_get_target_component(msg);
    riot_cmd_long->cmd_id = mavlink_msg_riot_cmd_long_get_cmd_id(msg);
    mavlink_msg_riot_cmd_long_get_data(msg, riot_cmd_long->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN? msg->len : MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN;
        memset(riot_cmd_long, 0, MAVLINK_MSG_ID_RIOT_CMD_LONG_LEN);
    memcpy(riot_cmd_long, _MAV_PAYLOAD(msg), len);
#endif
}
