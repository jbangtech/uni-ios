#
# Be sure to run `pod lib lint JBUniMP.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'JBangUniMP'
  s.version          = '0.1.5'
  s.summary          = 'JBUniMP'

  s.homepage         = 'https://github.com/jbangtech/uni-ios'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'ECHANEEZYY' => '553438532@qq.com' }
  s.source           = { :git => 'https://github.com/jbangtech/uni-ios.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.static_framework = true
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  
  s.subspec 'Core' do |core|
    core.resources = ['JBangUniMP/Classes/Core/Resources/*', 'JBangUniMP/Classes/Features/Resources/*']
    core.source_files = 'JBangUniMP/Classes/JBUniMP.framework/Headers/*.{h}', 'JBangUniMP/Classes/Core/Headers/*.{h}', 'JBangUniMP/Classes/Features/inc/**/*.h'
    core.vendored_libraries = 'JBangUniMP/Classes/Core/Libs/*.a', 'JBangUniMP/Classes/Features/Libs/*.a'
    core.vendored_frameworks = 'JBangUniMP/Classes/*.framework', 'JBangUniMP/Classes/Features/Libs/*.framework'
    core.public_header_files = 'JBangUniMP/Classes/JBUniMP.framework/Headers/JBUniMP.h'
    
    core.frameworks = 'Foundation', 'UIKit', 'JavaScriptCore', 'AVFoundation', 'OpenGLES', 'CoreGraphics', 'CoreTelephony', 'AddressBook', 'CoreMedia', 'AVKit', 'CoreText', 'AssetsLibrary', 'MediaPlayer', 'GLKit', 'QuartzCore', 'QuickLook', 'CoreLocation', 'SystemConfiguration', 'Photos'
    core.libraries = 'c++', 'iconv', 'sqlite3.0', 'z'
    core.dependency 'AFNetworking'
    core.dependency 'SDWebImage'
    core.dependency 'MBProgressHUD'
    core.dependency 'MBProgressHUD'
  end
  
  s.subspec 'Firebase' do |firebase|
    firebase.source_files = 'JBangUniMP/Classes/Firebase/*.{h,m}'
    firebase.dependency 'FirebaseAnalytics'
    firebase.dependency 'FirebaseMessaging'
    firebase.dependency 'FirebaseStorage', '~> 8.15.0'
    firebase.dependency 'FirebaseAuth'
  end
  
end
