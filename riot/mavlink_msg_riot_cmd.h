#pragma once
// MESSAGE RIOT_CMD PACKING

#define MAVLINK_MSG_ID_RIOT_CMD 1000

MAVPACKED(
typedef struct __mavlink_riot_cmd_t {
 uint8_t target_system; /*<  System ID of target system this message is for.*/
 uint8_t target_component; /*<  Component ID of target Rapid IoT this message is for.*/
 uint8_t cmd_id; /*<  RIOT Command ID.*/
}) mavlink_riot_cmd_t;

#define MAVLINK_MSG_ID_RIOT_CMD_LEN 3
#define MAVLINK_MSG_ID_RIOT_CMD_MIN_LEN 3
#define MAVLINK_MSG_ID_1000_LEN 3
#define MAVLINK_MSG_ID_1000_MIN_LEN 3

#define MAVLINK_MSG_ID_RIOT_CMD_CRC 71
#define MAVLINK_MSG_ID_1000_CRC 71



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RIOT_CMD { \
    1000, \
    "RIOT_CMD", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_riot_cmd_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_riot_cmd_t, target_component) }, \
         { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_riot_cmd_t, cmd_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RIOT_CMD { \
    "RIOT_CMD", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_riot_cmd_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_riot_cmd_t, target_component) }, \
         { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_riot_cmd_t, cmd_id) }, \
         } \
}
#endif

/**
 * @brief Pack a riot_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID of target system this message is for.
 * @param target_component  Component ID of target Rapid IoT this message is for.
 * @param cmd_id  RIOT Command ID.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_riot_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t cmd_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_CMD_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, cmd_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RIOT_CMD_LEN);
#else
    mavlink_riot_cmd_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.cmd_id = cmd_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RIOT_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RIOT_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RIOT_CMD_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LEN, MAVLINK_MSG_ID_RIOT_CMD_CRC);
}

/**
 * @brief Pack a riot_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID of target system this message is for.
 * @param target_component  Component ID of target Rapid IoT this message is for.
 * @param cmd_id  RIOT Command ID.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_riot_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t cmd_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_CMD_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, cmd_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RIOT_CMD_LEN);
#else
    mavlink_riot_cmd_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.cmd_id = cmd_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RIOT_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RIOT_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RIOT_CMD_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LEN, MAVLINK_MSG_ID_RIOT_CMD_CRC);
}

/**
 * @brief Encode a riot_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param riot_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_riot_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_riot_cmd_t* riot_cmd)
{
    return mavlink_msg_riot_cmd_pack(system_id, component_id, msg, riot_cmd->target_system, riot_cmd->target_component, riot_cmd->cmd_id);
}

/**
 * @brief Encode a riot_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param riot_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_riot_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_riot_cmd_t* riot_cmd)
{
    return mavlink_msg_riot_cmd_pack_chan(system_id, component_id, chan, msg, riot_cmd->target_system, riot_cmd->target_component, riot_cmd->cmd_id);
}

/**
 * @brief Send a riot_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID of target system this message is for.
 * @param target_component  Component ID of target Rapid IoT this message is for.
 * @param cmd_id  RIOT Command ID.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_riot_cmd_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t cmd_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_CMD_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, cmd_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD, buf, MAVLINK_MSG_ID_RIOT_CMD_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LEN, MAVLINK_MSG_ID_RIOT_CMD_CRC);
#else
    mavlink_riot_cmd_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.cmd_id = cmd_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD, (const char *)&packet, MAVLINK_MSG_ID_RIOT_CMD_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LEN, MAVLINK_MSG_ID_RIOT_CMD_CRC);
#endif
}

/**
 * @brief Send a riot_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_riot_cmd_send_struct(mavlink_channel_t chan, const mavlink_riot_cmd_t* riot_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_riot_cmd_send(chan, riot_cmd->target_system, riot_cmd->target_component, riot_cmd->cmd_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD, (const char *)riot_cmd, MAVLINK_MSG_ID_RIOT_CMD_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LEN, MAVLINK_MSG_ID_RIOT_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_RIOT_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_riot_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t cmd_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, cmd_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD, buf, MAVLINK_MSG_ID_RIOT_CMD_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LEN, MAVLINK_MSG_ID_RIOT_CMD_CRC);
#else
    mavlink_riot_cmd_t *packet = (mavlink_riot_cmd_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->cmd_id = cmd_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_CMD, (const char *)packet, MAVLINK_MSG_ID_RIOT_CMD_MIN_LEN, MAVLINK_MSG_ID_RIOT_CMD_LEN, MAVLINK_MSG_ID_RIOT_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE RIOT_CMD UNPACKING


/**
 * @brief Get field target_system from riot_cmd message
 *
 * @return  System ID of target system this message is for.
 */
static inline uint8_t mavlink_msg_riot_cmd_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from riot_cmd message
 *
 * @return  Component ID of target Rapid IoT this message is for.
 */
static inline uint8_t mavlink_msg_riot_cmd_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field cmd_id from riot_cmd message
 *
 * @return  RIOT Command ID.
 */
static inline uint8_t mavlink_msg_riot_cmd_get_cmd_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a riot_cmd message into a struct
 *
 * @param msg The message to decode
 * @param riot_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_riot_cmd_decode(const mavlink_message_t* msg, mavlink_riot_cmd_t* riot_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    riot_cmd->target_system = mavlink_msg_riot_cmd_get_target_system(msg);
    riot_cmd->target_component = mavlink_msg_riot_cmd_get_target_component(msg);
    riot_cmd->cmd_id = mavlink_msg_riot_cmd_get_cmd_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RIOT_CMD_LEN? msg->len : MAVLINK_MSG_ID_RIOT_CMD_LEN;
        memset(riot_cmd, 0, MAVLINK_MSG_ID_RIOT_CMD_LEN);
    memcpy(riot_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
