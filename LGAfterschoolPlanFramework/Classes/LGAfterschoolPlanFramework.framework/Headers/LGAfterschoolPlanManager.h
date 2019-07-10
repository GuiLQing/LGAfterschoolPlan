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
#define LGAPTrainModekey [NSString stringWithFormat:@"%@%@%@", LGAPManager.userID, LGAPManager.freeStudyBaseUrl, @"TrainModekey"]

NS_ASSUME_NONNULL_BEGIN

@interface LGAfterschoolPlanManager : NSObject

/** 用户ID */
@property (nonatomic, strong) NSString *userID;
/** 用户名 */
@property (nonatomic, strong) NSString *userName;

@property (nonatomic, strong) NSString *subjectID;

@property (nonatomic, strong) NSString *globalGrade;

@property (nonatomic, strong) NSString *freeStudyBaseUrl;

@property (nonatomic, strong) NSString *englishTrainingBaseUrl;

@property (nonatomic, strong) NSString *studyLevel;

@property (nonatomic, strong, readonly) NSString *subjectCode;

@property (nonatomic, assign, readonly) NSInteger levelId;
/** trainingType 词汇听写：1， 句子听写：2， 听力选择：3 */
@property (nonatomic, copy) void (^jumpToEnglishTrainingBlock)(UIViewController *fromController, NSString *planId, NSInteger trainingType, NSString *resCode, NSNumber *lastProgress);

+ (LGAfterschoolPlanManager *)defaultManager;

- (void)presentAfterschoolPlanControllerBy:(UIViewController *)controller;
- (void (^)(UIViewController *controller))presentAfterschoolPlanController;

@end

NS_ASSUME_NONNULL_END
