#pragma once
// MESSAGE RIOT_RESPONSE PACKING

#define MAVLINK_MSG_ID_RIOT_RESPONSE 1010

MAVPACKED(
typedef struct __mavlink_riot_response_t {
 float humidity; /*<  Floating point value for humidity sensor data.*/
 float temperature; /*<  Floating point value for temperature sensor data.*/
 uint16_t air_quality; /*<  Unsigned integer value for air quality sensor data. Value typically between 400 and 8000.*/
 uint8_t cmd_id; /*<  RIOT Short Command ID the response is for.*/
}) mavlink_riot_response_t;

#define MAVLINK_MSG_ID_RIOT_RESPONSE_LEN 11
#define MAVLINK_MSG_ID_RIOT_RESPONSE_MIN_LEN 11
#define MAVLINK_MSG_ID_1010_LEN 11
#define MAVLINK_MSG_ID_1010_MIN_LEN 11

#define MAVLINK_MSG_ID_RIOT_RESPONSE_CRC 62
#define MAVLINK_MSG_ID_1010_CRC 62



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RIOT_RESPONSE { \
    1010, \
    "RIOT_RESPONSE", \
    4, \
    {  { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_riot_response_t, cmd_id) }, \
         { "air_quality", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_riot_response_t, air_quality) }, \
         { "humidity", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_riot_response_t, humidity) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_riot_response_t, temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RIOT_RESPONSE { \
    "RIOT_RESPONSE", \
    4, \
    {  { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_riot_response_t, cmd_id) }, \
         { "air_quality", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_riot_response_t, air_quality) }, \
         { "humidity", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_riot_response_t, humidity) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_riot_response_t, temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a riot_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cmd_id  RIOT Short Command ID the response is for.
 * @param air_quality  Unsigned integer value for air quality sensor data. Value typically between 400 and 8000.
 * @param humidity  Floating point value for humidity sensor data.
 * @param temperature  Floating point value for temperature sensor data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_riot_response_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t cmd_id, uint16_t air_quality, float humidity, float temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_RESPONSE_LEN];
    _mav_put_float(buf, 0, humidity);
    _mav_put_float(buf, 4, temperature);
    _mav_put_uint16_t(buf, 8, air_quality);
    _mav_put_uint8_t(buf, 10, cmd_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN);
#else
    mavlink_riot_response_t packet;
    packet.humidity = humidity;
    packet.temperature = temperature;
    packet.air_quality = air_quality;
    packet.cmd_id = cmd_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RIOT_RESPONSE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RIOT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_CRC);
}

/**
 * @brief Pack a riot_response message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_id  RIOT Short Command ID the response is for.
 * @param air_quality  Unsigned integer value for air quality sensor data. Value typically between 400 and 8000.
 * @param humidity  Floating point value for humidity sensor data.
 * @param temperature  Floating point value for temperature sensor data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_riot_response_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t cmd_id,uint16_t air_quality,float humidity,float temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_RESPONSE_LEN];
    _mav_put_float(buf, 0, humidity);
    _mav_put_float(buf, 4, temperature);
    _mav_put_uint16_t(buf, 8, air_quality);
    _mav_put_uint8_t(buf, 10, cmd_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN);
#else
    mavlink_riot_response_t packet;
    packet.humidity = humidity;
    packet.temperature = temperature;
    packet.air_quality = air_quality;
    packet.cmd_id = cmd_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RIOT_RESPONSE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RIOT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_CRC);
}

/**
 * @brief Encode a riot_response struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param riot_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_riot_response_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_riot_response_t* riot_response)
{
    return mavlink_msg_riot_response_pack(system_id, component_id, msg, riot_response->cmd_id, riot_response->air_quality, riot_response->humidity, riot_response->temperature);
}

/**
 * @brief Encode a riot_response struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param riot_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_riot_response_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_riot_response_t* riot_response)
{
    return mavlink_msg_riot_response_pack_chan(system_id, component_id, chan, msg, riot_response->cmd_id, riot_response->air_quality, riot_response->humidity, riot_response->temperature);
}

/**
 * @brief Send a riot_response message
 * @param chan MAVLink channel to send the message
 *
 * @param cmd_id  RIOT Short Command ID the response is for.
 * @param air_quality  Unsigned integer value for air quality sensor data. Value typically between 400 and 8000.
 * @param humidity  Floating point value for humidity sensor data.
 * @param temperature  Floating point value for temperature sensor data.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_riot_response_send(mavlink_channel_t chan, uint8_t cmd_id, uint16_t air_quality, float humidity, float temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RIOT_RESPONSE_LEN];
    _mav_put_float(buf, 0, humidity);
    _mav_put_float(buf, 4, temperature);
    _mav_put_uint16_t(buf, 8, air_quality);
    _mav_put_uint8_t(buf, 10, cmd_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE, buf, MAVLINK_MSG_ID_RIOT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_CRC);
#else
    mavlink_riot_response_t packet;
    packet.humidity = humidity;
    packet.temperature = temperature;
    packet.air_quality = air_quality;
    packet.cmd_id = cmd_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE, (const char *)&packet, MAVLINK_MSG_ID_RIOT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_CRC);
#endif
}

/**
 * @brief Send a riot_response message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_riot_response_send_struct(mavlink_channel_t chan, const mavlink_riot_response_t* riot_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_riot_response_send(chan, riot_response->cmd_id, riot_response->air_quality, riot_response->humidity, riot_response->temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE, (const char *)riot_response, MAVLINK_MSG_ID_RIOT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_CRC);
#endif
}

#if MAVLINK_MSG_ID_RIOT_RESPONSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_riot_response_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t cmd_id, uint16_t air_quality, float humidity, float temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, humidity);
    _mav_put_float(buf, 4, temperature);
    _mav_put_uint16_t(buf, 8, air_quality);
    _mav_put_uint8_t(buf, 10, cmd_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE, buf, MAVLINK_MSG_ID_RIOT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_CRC);
#else
    mavlink_riot_response_t *packet = (mavlink_riot_response_t *)msgbuf;
    packet->humidity = humidity;
    packet->temperature = temperature;
    packet->air_quality = air_quality;
    packet->cmd_id = cmd_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RIOT_RESPONSE, (const char *)packet, MAVLINK_MSG_ID_RIOT_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN, MAVLINK_MSG_ID_RIOT_RESPONSE_CRC);
#endif
}
#endif

#endif

// MESSAGE RIOT_RESPONSE UNPACKING


/**
 * @brief Get field cmd_id from riot_response message
 *
 * @return  RIOT Short Command ID the response is for.
 */
static inline uint8_t mavlink_msg_riot_response_get_cmd_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field air_quality from riot_response message
 *
 * @return  Unsigned integer value for air quality sensor data. Value typically between 400 and 8000.
 */
static inline uint16_t mavlink_msg_riot_response_get_air_quality(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field humidity from riot_response message
 *
 * @return  Floating point value for humidity sensor data.
 */
static inline float mavlink_msg_riot_response_get_humidity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field temperature from riot_response message
 *
 * @return  Floating point value for temperature sensor data.
 */
static inline float mavlink_msg_riot_response_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a riot_response message into a struct
 *
 * @param msg The message to decode
 * @param riot_response C-struct to decode the message contents into
 */
static inline void mavlink_msg_riot_response_decode(const mavlink_message_t* msg, mavlink_riot_response_t* riot_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    riot_response->humidity = mavlink_msg_riot_response_get_humidity(msg);
    riot_response->temperature = mavlink_msg_riot_response_get_temperature(msg);
    riot_response->air_quality = mavlink_msg_riot_response_get_air_quality(msg);
    riot_response->cmd_id = mavlink_msg_riot_response_get_cmd_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RIOT_RESPONSE_LEN? msg->len : MAVLINK_MSG_ID_RIOT_RESPONSE_LEN;
        memset(riot_response, 0, MAVLINK_MSG_ID_RIOT_RESPONSE_LEN);
    memcpy(riot_response, _MAV_PAYLOAD(msg), len);
#endif
}
