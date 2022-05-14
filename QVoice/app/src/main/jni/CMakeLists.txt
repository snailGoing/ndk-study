cmake_minimum_required(VERSION 3.6.0)

# 导入头文件
include_directories("inc")

# 批量导入所有源文件
file(GLOB allCPP *.c *.h *.cpp)

add_library(
        native-lib
        SHARED
        ${allCPP}
)

# TODO 第二步：导入库文件，表示在环境变量 CMAKE_CXX_FLAGS 后追加配置
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}")

# TODO 第三步，链接具体的库，到我们的 libnative-lib.so总库
target_link_libraries(
        native-lib
        #${log-varAAAA}
        log # 自动寻找  # 具体的库 链接到 libnative-lib.so里面去
        fmod # 具体的库 链接到 libnative-lib.so里面去
        fmodL # 具体的库 链接到 libnative-lib.so里面去
)