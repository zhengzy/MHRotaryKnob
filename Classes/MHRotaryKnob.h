
#import <UIKit/UIKit.h>

/*!
 * A rotary knob control.
 *
 * Operation of this control is similar to a UISlider. You can set a minimum,
 * maximum, and current value. When the knob is turned the control sends out
 * a \c UIControlEventValueChanged notification to its target-action.
 *
 * The control uses two images, one for the background and one for the knob. 
 * The background image is optional but you must set at least the knob image
 * before you can use the control.
 *
 * When double-tapped, the control resets to its default value, typically the
 * the center or minimum position. This feature can be disabled with the \c
 * resetsToDefault property.
 */
@interface MHRotaryKnob : UIControl
{
	UIImageView* backgroundImageView;  ///< shows the background image
	UIImageView* knobImageView;        ///< shows the knob image
	UIImage* knobImageNormal;          ///< knob image for normal state
	UIImage* knobImageHighlighted;     ///< knob image for highlighted state
	UIImage* knobImageDisabled;        ///< knob image for disabled state
	float angle;                       ///< for tracking touches
}

/*! The image that is drawn behind the knob. May be nil. */
@property (nonatomic, retain) UIImage* backgroundImage;

/*! The image currently being used to draw the knob. */
@property (nonatomic, retain, readonly) UIImage* currentKnobImage;

/*! The maximum value of the control. Default is 1.0f. */
@property (nonatomic, assign) float maximumValue;

/*! The minimum value of the control. Default is 0.0f. */
@property (nonatomic, assign) float minimumValue;

/*! The control's current value. Default is 0.5f (center position). */
@property (nonatomic, assign) float value;

/*! The control's default value. Default is 0.5f (center position). */
@property (nonatomic, assign) float defaultValue;

/*!
 * Whether the control resets to the default value on a double tap.
 * Default is YES.
 */
@property (nonatomic, assign) BOOL resetsToDefault;

/*!
 * Whether changes in the knob's value generate continuous update events. 
 * If NO, the control only sends an action event when the user releases the 
 * knob. The default is YES.
 */
@property (nonatomic, assign) BOOL continuous;

/*!
 * Sets the controls’s current value, allowing you to animate the change
 * visually.
 */
- (void)setValue:(float)value animated:(BOOL)animated;

/*!
 * Assigns a knob image to the specified control states.
 * 
 * This image should have its position indicator at the top. The knob image is
 * rotated when the control's value changes, so it's best to make it perfectly
 * round.
 */
- (void)setKnobImage:(UIImage*)image forState:(UIControlState)state;

/*!
 * Returns the thumb image associated with the specified control state.
 */
- (UIImage*)knobImageForState:(UIControlState)state;

@end
