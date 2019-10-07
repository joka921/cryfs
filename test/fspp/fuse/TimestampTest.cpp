#include "../testutils/FuseTest.h"

using namespace fspp::fuse;
using namespace fspp::fuse;


typedef FuseTest FuseTimestampTest;

TEST_F(FuseTimestampTest, whenCalledWithoutAnyAtimeFlag_thenHasRelatimeBehavior) {
    auto fs = TestFS({});
    EXPECT_EQ(fspp::relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithNoatimeFlag_thenHasNoatimeBehavior) {
    auto fs = TestFS({"-o", "noatime"});
    EXPECT_EQ(fspp::noatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithStrictatimeFlag_thenHasStrictatimeBehavior) {
    auto fs = TestFS({"-o", "strictatime"});
    EXPECT_EQ(fspp::strictatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithRelatimeFlag_thenHasRelatimeBehavior) {
    auto fs = TestFS({"-o", "relatime"});
    EXPECT_EQ(fspp::relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithAtimeFlag_thenHasRelatimeBehavior) {
    auto fs = TestFS({"-o", "atime"});
    EXPECT_EQ(fspp::relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithNodiratimeFlag_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "nodiratime"});
    EXPECT_EQ(fspp::nodiratime_relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithNodiratimeRelatimeFlag_withCsv_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "nodiratime,relatime"});
    EXPECT_EQ(fspp::nodiratime_relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithRelatimeNodiratimeFlag_withCsv_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "relatime,nodiratime"});
    EXPECT_EQ(fspp::nodiratime_relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithNodiratimeRelatimeFlag_withSeparateFlags_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "nodiratime", "-o", "relatime"});
    EXPECT_EQ(fspp::nodiratime_relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithRelatimeNodiratimeFlag_withSeparateFlags_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "relatime", "-o", "nodiratime"});
    EXPECT_EQ(fspp::nodiratime_relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithNodiratimeAtimeFlag_withCsv_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "nodiratime,atime"});
    EXPECT_EQ(fspp::nodiratime_relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithAtimeNodiratimeFlag_withCsv_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "atime,nodiratime"});
    EXPECT_EQ(fspp::nodiratime_relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithNodiratimeAtimeFlag_withSeparateFlags_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "nodiratime", "-o", "atime"});
    EXPECT_EQ(fspp::nodiratime_relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithAtimeNodiratimeFlag_withSeparateFlags_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "atime", "-o", "nodiratime"});
    EXPECT_EQ(fspp::nodiratime_relatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithNodiratimeStrictatimeFlag_withCsv_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "nodiratime,strictatime"});
    EXPECT_EQ(fspp::nodiratime_strictatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithStrictatimeNodiratimeFlag_withCsv_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "strictatime,nodiratime"});
    EXPECT_EQ(fspp::nodiratime_strictatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithNodiratimeStrictatimeFlag_withSeparateFlags_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "nodiratime", "-o", "strictatime"});
    EXPECT_EQ(fspp::nodiratime_strictatime().get(), context().timestampUpdateBehavior().get());
}

TEST_F(FuseTimestampTest, whenCalledWithStrictatimeNodiratimeFlag_withSeparateFlags_thenHasNodiratimeRelatimeBehavior) {
    auto fs = TestFS({"-o", "strictatime", "-o", "nodiratime"});
    EXPECT_EQ(fspp::nodiratime_strictatime().get(), context().timestampUpdateBehavior().get());
}

// TODO Test allowed flag combinations (i.e. repetitions, atime vs relatime). For both withCsv and withSeparateFlags.
// TODO Test disallowed flag combinations (e.g. relatime vs noatime). For both withCsv and withSeparateFlags.
