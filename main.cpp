#include <iostream>

#include <glog/logging.h>
#include <gflags/gflags.h>

static void init_glibs(int * argc, char ** argv[]) {
    google::SetVersionString("42");
    google::SetUsageMessage("Press button, receive bacon.");

    FLAGS_logtostderr = true;
    FLAGS_stderrthreshold = 0;
    FLAGS_minloglevel = 0;

    google::ParseCommandLineFlags(argc, argv, true);
    google::InitGoogleLogging(*argv[0]);
    google::InstallFailureSignalHandler();
}

int main(int argc, char * argv[]) {
    init_glibs(&argc, &argv);
    LOG(INFO) << __func__;

    return 0;
}
