//
//  IMNativeDelegate.h
//  APIs
//  Copyright (c) 2015 InMobi. All rights reserved.
//

/**
 * A listener for receiving notifications during the lifecycle of an native ad.
 *
 * Note All the events in this listener will be invoked on your application's UI thread.
 *
 * In most cases your application will need to listen for the following events on an native ad
 
 The outcome of an ad request (if the request succeeded or failed); 
 see nativeDidFinishLoading:(IMNative*)native; and native:(IMNative*)native didFailToLoadWithError:(IMRequestStatus*)error;
 
 The ad opened an overlay that covered the screen. This means that the user can no longer interact with your application; 
 see nativeDidPresentScreen:(IMNative*)native;
 
 The ad opened overlay was dismissed. The user is now free to interact with your application; 
 see nativeDidDismissScreen:(IMNative*)native;
 
 A user interaction with the ad will result in the User leaving your application context; 
 see userWillLeaveApplicationFromNative:(IMNative*)native;
 */
#import <Foundation/Foundation.h>
#import "IMRequestStatus.h"

typedef NS_ENUM(int, IMBidType) {
    kIMFirstPrice = 0,
    kIMSecondPrice = 1
};

@class IMNative;
@protocol IMNativeDelegate <NSObject>
@optional
/**
 * Notifies the delegate that the native ad has downloaded markup
 */
- (void)nativeAdIsAvailable:(IMNative *)native;

/**
 * The callback used to give the signals to the delegate. This callback is invoked after getSignals method is invoked on the IMNative instance.
 */
- (void)native:(IMNative *)native gotSignals:(NSData *)signals;

/**
 * Notifies the delegate that the getSignals call on the IMNative instance has failed to return the sginals.
 */
- (void)native:(IMNative *)native failedToGetSignalsWithError:(IMRequestStatus *)status;

/**
 * Notifies the delegate that the native ad has finished loading
 */
- (void)nativeDidFinishLoading:(IMNative *)native;

/**
 * Notifies the delegate that the native ad has failed to load with error.
 */
- (void)native:(IMNative *)native didFailToLoadWithError:(IMRequestStatus *)error;

/**
 * Notifies the delegate that the native ad would be presenting a full screen content.
 */
- (void)nativeWillPresentScreen:(IMNative *)native;

/**
 * Notifies the delegate that the native ad has presented a full screen content.
 */
- (void)nativeDidPresentScreen:(IMNative *)native;

/**
 * Notifies the delegate that the native ad would be dismissing the presented full screen content.
 */
- (void)nativeWillDismissScreen:(IMNative *)native;

/**
 * Notifies the delegate that the native ad has dismissed the presented full screen content.
 */
- (void)nativeDidDismissScreen:(IMNative *)native;

/**
 * Notifies the delegate that the user will be taken outside the application context.
 */
- (void)userWillLeaveApplicationFromNative:(IMNative *)native;

/**
 * Notifies the delegate that the native ad impression has been tracked
 */
- (void)nativeAdImpressed:(IMNative *)native;

/**
 * Notifies the delegate that the native ad has been interacted with.
 */
- (void)native:(IMNative *)native didInteractWithParams:(NSDictionary *)params;

/**
 * Notifies the delegate that the native ad has finished playing media.
 */
- (void)nativeDidFinishPlayingMedia:(IMNative *)native;

/**
 * Notifies the delegate that the user has skipped the playing media.
 */
- (void)userDidSkipPlayingMediaFromNative:(IMNative *)native;

/**
 * Notifies the delegate that the media audio state has been changed - mute/unmute.
 * @param audioStateMuted is YES when audio is turned off and NO when audio is turned on.
 */
- (void)native:(IMNative *)native adAudioStateChanged:(BOOL)audioStateMuted;

/**
 * Notifies the delegate that the secondary iniine native ad has failed to load with error.
 */
- (void)native:(IMNative *)native secondaryInlineAdDidFailToLoadWithError:(IMRequestStatus *)error;

/**
 * Passes the bid price and bid type
 */
- (void)bidPrice:(float)price bidType:(IMBidType)type;

@end
