Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "PTGInmobiAd"
  spec.version      = "7.5.2"
  spec.summary      = "A short description of PTGInmobiAd."


  spec.description  = <<-DESC
    PTGAdFramework provides Union ADs which include native、banner、feed、splash、RewardVideo etc.
  DESC

  spec.homepage     = "https://github.com/PTGAd/PTGInmobiAd"

  spec.license      = "MIT"

  spec.author       = { "xiangrongsu" => "15139093304@163.com" }

  spec.source       = { :git => "https://github.com/PTGAd/PTGInmobiAd.git", :tag => "#{spec.version }" }


  spec.platform   = :ios, "9.0"
  spec.frameworks = 'UIKit', 'SafariServices', 'CoreLocation', 'MapKit', 'AdSupport', 'CoreTelephony', 'SystemConfiguration', 'WebKit', 'ImageIO', 'Accelerate', 'Photos', 'AssetsLibrary', 'CoreServices'
  spec.libraries = 'c++','z', 'sqlite3.0','xm2'
  spec.vendored_frameworks =  'Frameworks/InMobiSDK.framework'
    
  valid_archs = ['armv7', 'armv7s','arm64','arm64e']
  spec.xcconfig = {
    'VALID_ARCHS' =>  valid_archs.join(' '),
  }

end
