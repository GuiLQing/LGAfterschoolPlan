//
//  LGAfterschoolPlanManager.h
//  LGAfterschoolPlanFramework
//
//  Created by lg on 2019/7/1.
//  Copyright © 2019 lg. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#define LGAPManager LGAfterschoolPlanManager.defaultManager
#define LGAPTrainingResGradeKey [NSString stringWithFormat:@"%@%@%@", LGAPManager.userID, LGAPManager.freeStudyBaseUrl, @"TrainResGradeKey"]
#define LGAPTrainModekey [NSString stringWithFormat:@"%@%@%@", LGAPManager.userID, LGAPManager.freeStudyBaseUrl, @"TrainModeKey"]

static NSInteger const LGAfterschoolPlanListenResourceDefaultMaxLimitCount = 20;

NS_ASSUME_NONNULL_BEGIN

@interface LGAfterschoolPlanManager : NSObject

+ (LGAfterschoolPlanManager *)defaultManager;

/** 用户ID */
@property (nonatomic, copy) NSString *userID;
/** 用户名 */
@property (nonatomic, copy) NSString *userName;

@property (nonatomic, copy) NSString *globalGrade;
/** 自学基础服务器地址 */
@property (nonatomic, copy) NSString *freeStudyBaseUrl;
/** 英语训练基础服务器地址 */
@property (nonatomic, copy) NSString *englishTrainingBaseUrl;

@property (nonatomic, copy) NSString *studyLevel;

/** 进入课外计划模块需要调用大数据推送登陆接口，要传入必要的参数 */
@property (nonatomic, copy) NSString *schoolName;   //学校名称
@property (nonatomic, copy) NSString *schoolID;     //学校ID
@property (nonatomic, copy) NSString *gradeName;    //年级名称
@property (nonatomic, copy) NSString *gradeID;      //年级ID
@property (nonatomic, copy) NSString *groupName;    //班级名称
@property (nonatomic, copy) NSString *groupID;      //班级ID
@property (nonatomic, copy) NSString *subjectName;  //学科名称
@property (nonatomic, copy) NSString *subjectID;    //学科ID
@property (nonatomic, copy) NSString *courseNO;     //课程ID
@property (nonatomic, copy) NSString *courseName;   //课程名称
@property (nonatomic, copy) NSString *token;        //用户登录令牌

/** 课外计划-听力训练中，选择听力资料的最大限制，default is LGAfterschoolPlanListenResourceDefaultMaxLimitCount */
@property (nonatomic, assign) NSInteger listenResourceMaxLimitCount;

/** 付费VIP模式 (default is YES) */
@property (nonatomic, assign) BOOL isVipMode;
/** 非VIP模式试听秒数 */
@property (nonatomic, assign) NSInteger nonVipListeningTestTime;
/** 是否开启非VIP限制 */
@property (nonatomic, assign, readonly) BOOL isOpenNonVipLimit;

@property (nonatomic, strong, readonly) NSString *subjectCode;

@property (nonatomic, assign, readonly) NSInteger levelId;

#pragma mark - 课外计划回调

@property (nonatomic, copy) void (^jumpToEnglishPreviewBlock)(UIViewController *fromController, NSInteger trainingMode, NSString *resType, NSString *resCode);

@property (nonatomic, copy) void (^jumpToEnglishTrainingBlock)(UIViewController *fromController, NSString *planId, NSInteger trainingMode, NSString *resType, NSString *resCode, NSNumber *lastProgress);

@property (nonatomic, copy) void (^afterschoolPlanWillDismissBlock)(void);

#pragma mark - 对接课外计划跳转

/** 跳转课外计划首页 */
- (void)presentAfterschoolPlanControllerBy:(UIViewController *)controller;
- (void (^)(UIViewController *controller))presentAfterschoolPlanController;
- (UINavigationController *)presentAfterschoolPlanHomeViewControllerWithBackHandler:(void (^)(void))backHandler;

/**
 跳转到课外计划详情界面

 @param studyPlanType 计划类型(1-词汇背诵，2-听力训练)
 @param planId 学习计划ID
 @param rangeId 阶段ID
 @param planState 任务状态(0-进行中，1-未开始, 2-已结束)
 @param planName 计划名称
 */
- (UINavigationController *)presentAfterschoolPlanDetailWithStudyPlanType:(NSInteger)studyPlanType planId:(NSString *)planId rangeId:(NSString *)rangeId planState:(NSInteger)planState planName:(NSString *)planName backHandler:(void (^)(void))backHandler;

- (void)presentAfterschoolPlanDetailVCBy:(UIViewController *)controller studyPlanType:(NSInteger)studyPlanType planId:(NSString *)planId rangeId:(NSString *)rangeId planState:(NSInteger)planState planName:(NSString *)planName;

@end

NS_ASSUME_NONNULL_END
