
Pod::Spec.new do |s|
    s.name             = 'LGAfterschoolPlan'
    s.version          = '1.2.4'
    s.summary          = 'A short description of LGAfterschoolPlanFramework.'
    
    s.description      = <<-DESC
    TODO: Add long description of the pod here.
    DESC
    
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    
    s.homepage         = 'https://github.com/GuiLQing/LGAfterschoolPlanFramework'
    s.author           = { 'GuiLQing' => 'gui950823@126.com' }
    s.source           = { :git => 'https://github.com/GuiLQing/LGAfterschoolPlanFramework.git', :tag => s.version.to_s }
    
    #s.homepage         = 'http://192.168.3.18:3000/pengshigui/LGAfterschoolPlanFramework'
    #s.author           = { 'pengshigui' => 'gui950823@126.com' }
    #s.source           = { :git => 'http://192.168.3.18:3000/pengshigui/LGAfterschoolPlanFramework.git', :tag => s.version.to_s }
    
    s.ios.deployment_target = '9.0'
    
    #系统依赖库
    s.frameworks = 'AudioToolbox', 'AVFoundation', 'CoreGraphics', 'CoreMedia', 'CoreVideo', 'MediaPlayer', 'MobileCoreServices', 'OpenGLES', 'QuartzCore', 'UIKit', 'VideoToolbox', 'Accelerate'
    s.libraries = 'z', 'bz2', 'stdc++'
    s.requires_arc = true
    s.static_framework  =  true
    
    #需要包含的源文件
    s.source_files = 'LGAfterschoolPlanFramework/Classes/LGAfterschoolPlanFramework.framework/Headers/*.{h}'
    
    #你的SDK路径
    s.vendored_frameworks = 'LGAfterschoolPlanFramework/Classes/LGAfterschoolPlanFramework.framework'
    
    s.resources = 'LGAfterschoolPlanFramework/Classes/LGAfterschoolPlanFramework.bundle'
    
    s.dependency 'AFNetworking','3.2.1'
    s.dependency 'Masonry'
    s.dependency 'JSONModel'
    s.dependency 'SDWebImage'
    s.dependency 'Reachability'
    s.dependency 'ReactiveObjC'
    s.dependency 'MJRefresh'
    s.dependency 'MarqueeLabel','3.2.0'
    s.dependency 'MBProgressHUD'
    s.dependency 'YYText'
    s.dependency 'MJExtension'
    s.dependency 'YJTaskMark'
    s.dependency 'YJPresentAnimation'
    s.dependency 'SG_Clock'
    s.dependency 'SGTools'
    s.dependency 'PSGChainedMode'
    s.dependency 'WZLBadge'
    s.dependency 'LGBundle'
    s.dependency 'YJImageBrowser'
    
end
