//
//  SearchIPCam.h
//  SearchIPCam
//
//  Created by aoni on 15/12/2.
//  Copyright (c) 2015年 aoni. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#if defined(WIN32) || defined(WINAPI_FAMILY)

#ifdef SEARCH_EXPORTS
#define SEARCH_API __declspec(dllexport)
#else
#define SEARCH_API __declspec(dllimport)
#endif

#else

#define SEARCH_API
#endif  //WIN32

#define 	MSG_HOSTNAME_LEN 		24
#define 	MSG_MAC_ADDR_SIZE		24
#define	 MSG_IP_SIZE 			16
#define 	MSG_VERSION_LEN		 24
#define  AMBAR_MAX_ADDR_SIZE	 4
#define	AMBAR_VERSION_LEN		 24
#define  AMBAR_MAX_OVERLAY_NUM		4
#define MSG_DATA_LEN 	(100*1024)
//搜索命令
#define MSG_BROADCAST_SEARCH 		0x851 //广播搜索设备
#define MSG_BROADCAST_MODIFY 		0x852 //广播修改IP
#define MSG_RESET_FACTORY_PARAM 	0x0853 //恢复出厂设置
#define MSG_SET_VERSION_INFO 		0x0854 //设置版本信息

typedef struct __msg_head_t
{
    unsigned short msg_type; //消息类型
    unsigned short msg_subtype; //消息子类型
    unsigned int msg_size; //消息长度
    unsigned char ack_flag; //确认标志
    unsigned char reserved[3];
}msg_head_t;//命令头
typedef struct _msg_broadcast_t
{
    int server_type; //设备类型
    int port_no; //监听端口
    int net_type; //网络类型  0 有线  1 无线
    char host_name[MSG_HOSTNAME_LEN]; //设备名
    char mac_addr[MSG_MAC_ADDR_SIZE]; //MAC地址
    char ip_addr[MSG_IP_SIZE]; //IP地址
    char net_mask[MSG_IP_SIZE]; //网络掩码
    char gw_addr[MSG_IP_SIZE]; //网关地址
    char version[MSG_VERSION_LEN];//版本信息
    unsigned int port_offset; //端口偏移
    char first_dns_addr[MSG_IP_SIZE]; //首选DNS地址
    char second_dns_addr[MSG_IP_SIZE]; //备用DNS地址
    unsigned short dns_manu_flag; //dns 手动标志: 1: enable, 0: disable
    unsigned short web_port; //web 端口
    char dhcp_flag; //dhcp 使能标志: 1:enable, 0: disable
    char gw_devtype; //0:使用此网卡默认网关 1：没使用此网卡的默认网关
    char unused[2];
    char device_ID [MSG_VERSION_LEN];                //设备ID
}msg_broadcast_t;

typedef struct __net_msg_t
{
    msg_head_t msg_head; //消息头  对应搜索命令
    char msg_data[MSG_DATA_LEN]; //消息数据
}net_msg_t;

@interface SearchIPCam : NSObject
//设备搜索
- SEARCH_API(void)startSearch;
//获取设备名称
- SEARCH_API(NSString *)getDeviceNames;
//获取设备MAC地址
- SEARCH_API(NSString *)getMacAddress;
//获取设备IP
- SEARCH_API(NSString *)getDeviceIp;
//获取设备端口
- SEARCH_API(NSString *)getDevicePort;
@end
