//
//  FeatureToggle.h
//  SpriteBuilder
//
//  Created by Nicky Weber on 28.05.14.
//
//

/* loads and parses a feature.config.json file, format is:
 *
 * {
 *    "myFeature" : true,
 *    "anotherFeature" : false,
 *    ...
 * }
 *
 * Define your feature toggles as properties, see below.
 * Properties are set with KVC
 *
 */

@interface FeatureToggle : NSObject

// *** Add features as BOOL properties, name has to match key in feature.config.json, use custom getter
// to improve readability. Example:
//
// @property (nonatomic, getter=isMyFeatureEnabled, readonly) BOOL myFeature;

@property (nonatomic, getter=arePackagesEnabled, readonly) BOOL packages;

+ (FeatureToggle *)sharedFeatures;

- (void)loadFeatureJsonConfigFromBundleWithFileName:(NSString *)fileName;
- (void)loadFeaturesWithJsonData:(NSData *)data;

@end
