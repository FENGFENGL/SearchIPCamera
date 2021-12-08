//
//  ViewController.m
//  SearchIPDemo
//
//  Created by Eden on 8/12/2021.
//

#import "ViewController.h"
#import "include/SearchIPCam/SearchIPCam.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    SearchIPCam * cam = [[SearchIPCam alloc] init];
    
    [cam startSearch];
    NSLog(@"%@",[cam getDeviceNames]);
    NSLog(@"%@",[cam getMacAddress]);
    NSLog(@"%@",[cam getDeviceIp]);
    NSLog(@"%@",[cam getDevicePort]);
}


@end
