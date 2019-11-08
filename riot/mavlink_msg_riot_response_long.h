#pragma once
// MESSAGE RIOT_RESPONSE_LONG PACKING

#define MAVLINK_MSG_ID_RIOT_RESPONSE_LONG 1006

MAVPACKED(
typedef struct __mavlink_riot_response_long_t {
 uint8_t src_system; /*<  System ID of Rapid IoT component this response is from.*/
 uint8_t src_component; /*<  Component ID of Rapid IoT component this response is from.*/
 uint8_t cmd_id; /*<  RIOT Command ID the response is for.*/
 uint8_t data[128]; /*<  Data array of size 128 bytes to allow for returning bigger data such as the A100x Certificate.*/
}) mavlink_riot_response_long_t;

#define MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN 131
#define MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_MIN_LEN 131
#define MAVLINK_MSG_ID_1006_LEN 131
#define MAVLINK_MSG_ID_1006_MIN_LEN 131

#define MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_CRC 235
#define MAVLINK_MSG_ID_1006_CRC 235

#define MAVLINK_MSG_RIOT_RESPONSE_LONG_FIELD_DATA_LEN 128

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RIOT_RESPONSE_LONG { \
    1006, \
    "RIOT_RESPONSE_LONG", \
    4, \
    {  { "src_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_riot_response_long_t, src_system) }, \
         { "src_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_riot_response_long_t, src_component) }, \
         { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_riot_response_long_t, cmd_id) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 128, 3, offsetof(mavlink_riot_response_long_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RIOT_RESPONSE_LONG { \
    "RIOT_RESPONSE_LONG", \
    4, \
    {  { "src_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_riot_response_long_t, src_system) }, \
         { "src_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_riot_response_long_t, src_component) }, \
         { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_riot_response_long_t, cmd_id) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 128, 3, offsetof(mavlink_riot_response_long_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a riot_response_long message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param src_system  System ID of Rapid IoT component this response is from.
 * @param src_component  Component ID of Rapid IoT component this response is from.
 * @param cmd_id  RIOT Command ID the response is for.
 * @param data  Data array of size 128 bytes to allow for returning bigger data such as the A100x Certificate.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_riot_response_long_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t src_system, uint8_t src_component, uint8_t cmd_id, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN];
    _mav_put_uint8_t(buf, 0, src_system);
    _mav_put_uint8_t(buf, 1, src_component);
    _mav_put_uint8_t(buf, 2, cmd_id);
    _mav_put_uint8_t_array(buf, 3, data, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN);
#else
    mavlink_riot_response_long_t packet;
    packet.src_system = src_system;
    packet.src_component = src_component;
    packet.cmd_id = cmd_id;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RIOT_RESPONSE_LONG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_CRC);
}

/**
 * @brief Pack a riot_response_long message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param src_system  System ID of Rapid IoT component this response is from.
 * @param src_component  Component ID of Rapid IoT component this response is from.
 * @param cmd_id  RIOT Command ID the response is for.
 * @param data  Data array of size 128 bytes to allow for returning bigger data such as the A100x Certificate.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_riot_response_long_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t src_system,uint8_t src_component,uint8_t cmd_id,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN];
    _mav_put_uint8_t(buf, 0, src_system);
    _mav_put_uint8_t(buf, 1, src_component);
    _mav_put_uint8_t(buf, 2, cmd_id);
    _mav_put_uint8_t_array(buf, 3, data, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN);
#else
    mavlink_riot_response_long_t packet;
    packet.src_system = src_system;
    packet.src_component = src_component;
    packet.cmd_id = cmd_id;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RIOT_RESPONSE_LONG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_CRC);
}

/**
 * @brief Encode a riot_response_long struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param riot_response_long C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_riot_response_long_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_riot_response_long_t* riot_response_long)
{
    return mavlink_msg_riot_response_long_pack(system_id, component_id, msg, riot_response_long->src_system, riot_response_long->src_component, riot_response_long->cmd_id, riot_response_long->data);
}

/**
 * @brief Encode a riot_response_long struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param riot_response_long C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_riot_response_long_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_riot_response_long_t* riot_response_long)
{
    return mavlink_msg_riot_response_long_pack_chan(system_id, component_id, chan, msg, riot_response_long->src_system, riot_response_long->src_component, riot_response_long->cmd_id, riot_response_long->data);
}

/**
 * @brief Send a riot_response_long message
 * @param chan MAVLink channel to send the message
 *
 * @param src_system  System ID of Rapid IoT component this response is from.
 * @param src_component  Component ID of Rapid IoT component this response is from.
 * @param cmd_id  RIOT Command ID the response is for.
 * @param data  Data array of size 128 bytes to allow for returning bigger data such as the A100x Certificate.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_riot_response_long_send(mavlink_channel_t chan, uint8_t src_system, uint8_t src_component, uint8_t cmd_id, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN];
    _mav_put_uint8_t(buf, 0, src_system);
    _mav_put_uint8_t(buf, 1, src_component);
    _mav_put_uint8_t(buf, 2, cmd_id);
    _mav_put_uint8_t_array(buf, 3, data, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG, buf, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_CRC);
#else
    mavlink_riot_response_long_t packet;
    packet.src_system = src_system;
    packet.src_component = src_component;
    packet.cmd_id = cmd_id;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG, (const char *)&packet, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_CRC);
#endif
}

/**
 * @brief Send a riot_response_long message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_riot_response_long_send_struct(mavlink_channel_t chan, const mavlink_riot_response_long_t* riot_response_long)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_riot_response_long_send(chan, riot_response_long->src_system, riot_response_long->src_component, riot_response_long->cmd_id, riot_response_long->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG, (const char *)riot_response_long, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_CRC);
#endif
}

#if MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_riot_response_long_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t src_system, uint8_t src_component, uint8_t cmd_id, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, src_system);
    _mav_put_uint8_t(buf, 1, src_component);
    _mav_put_uint8_t(buf, 2, cmd_id);
    _mav_put_uint8_t_array(buf, 3, data, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG, buf, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_CRC);
#else
    mavlink_riot_response_long_t *packet = (mavlink_riot_response_long_t *)msgbuf;
    packet->src_system = src_system;
    packet->src_component = src_component;
    packet->cmd_id = cmd_id;
    mav_array_memcpy(packet->data, data, sizeof(uint8_t)*128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG, (const char *)packet, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_CRC);
#endif
}
#endif

#endif

// MESSAGE RIOT_RESPONSE_LONG UNPACKING


/**
 * @brief Get field src_system from riot_response_long message
 *
 * @return  System ID of Rapid IoT component this response is from.
 */
static inline uint8_t mavlink_msg_riot_response_long_get_src_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field src_component from riot_response_long message
 *
 * @return  Component ID of Rapid IoT component this response is from.
 */
static inline uint8_t mavlink_msg_riot_response_long_get_src_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field cmd_id from riot_response_long message
 *
 * @return  RIOT Command ID the response is for.
 */
static inline uint8_t mavlink_msg_riot_response_long_get_cmd_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field data from riot_response_long message
 *
 * @return  Data array of size 128 bytes to allow for returning bigger data such as the A100x Certificate.
 */
static inline uint16_t mavlink_msg_riot_response_long_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 128,  3);
}

/**
 * @brief Decode a riot_response_long message into a struct
 *
 * @param msg The message to decode
 * @param riot_response_long C-struct to decode the message contents into
 */
static inline void mavlink_msg_riot_response_long_decode(const mavlink_message_t* msg, mavlink_riot_response_long_t* riot_response_long)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    riot_response_long->src_system = mavlink_msg_riot_response_long_get_src_system(msg);
    riot_response_long->src_component = mavlink_msg_riot_response_long_get_src_component(msg);
    riot_response_long->cmd_id = mavlink_msg_riot_response_long_get_cmd_id(msg);
    mavlink_msg_riot_response_long_get_data(msg, riot_response_long->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN? msg->len : MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN;
        memset(riot_response_long, 0, MAVLINK_MSG_ID_RIOT_RESPONSE_LONG_LEN);
    memcpy(riot_response_long, _MAV_PAYLOAD(msg), len);
#endif
}
