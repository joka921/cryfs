#pragma once
#ifndef MESSMER_FSPP_FSTEST_FSPPDIRTEST_TIMESTAMPS_H_
#define MESSMER_FSPP_FSTEST_FSPPDIRTEST_TIMESTAMPS_H_

#include "testutils/TimestampTestUtils.h"

// FsppDirTest_Timestamps is split into _1 and _2 because of googletest limitations on number of test cases per
// type parametrized fixture
template<class ConcreteFileSystemTestFixture>
class FsppDirTest_Timestamps_1: public TimestampTestUtils<ConcreteFileSystemTestFixture> {
public:
};
TYPED_TEST_CASE_P(FsppDirTest_Timestamps_1);

template<class ConcreteFileSystemTestFixture>
class FsppDirTest_Timestamps_2: public TimestampTestUtils<ConcreteFileSystemTestFixture> {
public:
};
TYPED_TEST_CASE_P(FsppDirTest_Timestamps_2);

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNoatime_createAndOpenFile) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenStrictatime_createAndOpenFile) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenRelatime_createAndOpenFile) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeRelatime_createAndOpenFile) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeStrictatime_createAndOpenFile) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

/* TODO Re-enable this test once the root dir handles timestamps correctly
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNoatime_createAndOpenFile_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenStrictatime_createAndOpenFile_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenRelatime_createAndOpenFile_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeRelatime_createAndOpenFile_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeStrictatime_createAndOpenFile_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}*/

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNoatime_createAndOpenFile_TimestampsOfCreatedFile) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenStrictatime_createAndOpenFile_TimestampsOfCreatedFile) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenRelatime_createAndOpenFile_TimestampsOfCreatedFile) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeRelatime_createAndOpenFile_TimestampsOfCreatedFile) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeStrictatime_createAndOpenFile_TimestampsOfCreatedFile) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createAndOpenFile("childname", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNoatime_createDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenStrictatime_createDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenRelatime_createDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeRelatime_createDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeStrictatime_createDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

/* TODO Re-enable this test once the root dir handles timestamps correctly
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNoatime_createDir_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenStrictatime_createDir_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenRelatime_createDir_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeRelatime_createDir_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeStrictatime_createDir_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
*/

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNoatime_createDir_TimestampsOfCreatedDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenStrictatime_createDir_TimestampsOfCreatedDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenRelatime_createDir_TimestampsOfCreatedDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeRelatime_createDir_TimestampsOfCreatedDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeStrictatime_createDir_TimestampsOfCreatedDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createDir("childname", fspp::mode_t().addDirFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNoatime_createSymlink) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenStrictatime_createSymlink) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenRelatime_createSymlink) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeRelatime_createSymlink) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeStrictatime_createSymlink) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}

/* TODO Re-enable this test once the root dir handles timestamps correctly
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNoatime_createSymlink_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenStrictatime_createSymlink_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenRelatime_createSymlink_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeRelatime_createSymlink_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeStrictatime_createSymlink_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->LoadDir("/");
    auto operation = [&dir] () {
        dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
}
*/

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNoatime_createSymlink_TimestampsOfCreatedSymlink) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenStrictatime_createSymlink_TimestampsOfCreatedSymlink) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenRelatime_createSymlink_TimestampsOfCreatedSymlink) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeRelatime_createSymlink_TimestampsOfCreatedSymlink) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_1, givenNodiratimeStrictatime_createSymlink_TimestampsOfCreatedSymlink) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    timespec lowerBound = cpputils::time::now();
    dir->createSymlink("childname", "/target", fspp::uid_t(1000), fspp::gid_t(1000));
    timespec upperBound = cpputils::time::now();
    auto child = this->Load("/mydir/childname");
    this->EXPECT_ACCESS_TIMESTAMP_BETWEEN        (lowerBound, upperBound, *child);
    this->EXPECT_MODIFICATION_TIMESTAMP_BETWEEN  (lowerBound, upperBound, *child);
    this->EXPECT_METADATACHANGE_TIMESTAMP_BETWEEN(lowerBound, upperBound, *child);
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeNewerThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeOlderThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeBeforeYesterday_children_empty) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeNewerThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeOlderThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeBeforeYesterday_children_empty) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeNewerThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeOlderThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeBeforeYesterday_children_empty) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeNewerThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeOlderThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeBeforeYesterday_children_empty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeNewerThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeOlderThanMtime_children_empty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeBeforeYesterday_children_empty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

/* TODO Re-enable this test once the root dir handles timestamps correctly
TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeNewerThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeOlderThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeBeforeYesterday_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->LoadDir("/");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeNewerThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeOlderThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeBeforeYesterday_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->LoadDir("/");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeNewerThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeOlderThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeBeforeYesterday_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->LoadDir("/");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeNewerThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeOlderThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeBeforeYesterday_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->LoadDir("/");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeNewerThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeOlderThanMtime_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->LoadDir("/");
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeBeforeYesterday_children_empty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->LoadDir("/");
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}
*/

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeNewerThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeOlderThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeBeforeYesterday_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeNewerThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeOlderThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeBeforeYesterday_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeNewerThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeOlderThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeBeforeYesterday_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeNewerThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeOlderThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeBeforeYesterday_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeNewerThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeOlderThanMtime_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeBeforeYesterday_children_nonempty) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->CreateDir("/mydir");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

/* TODO Re-enable this test once the root dir handles timestamps correctly
TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeNewerThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeOlderThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNoatime_withAtimeBeforeYesterday_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::noatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeNewerThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeOlderThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenStrictatime_withAtimeBeforeYesterday_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::strictatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeNewerThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeOlderThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenRelatime_withAtimeBeforeYesterday_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::relatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectUpdatesAccessTimestamp, this->ExpectDoesntUpdateModificationTimestamp, this->ExpectDoesntUpdateMetadataTimestamp});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeNewerThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeOlderThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeRelatime_withAtimeBeforeYesterday_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeNewerThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampLaterThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeOlderThanMtime_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setModificationTimestampOlderThanAccessTimestamp("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}

TYPED_TEST_P(FsppDirTest_Timestamps_2, givenNodiratimeStrictatime_withAtimeBeforeYesterday_children_nonempty_inRootDir) {
    this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

    auto dir = this->LoadDir("/");
    dir->createAndOpenFile("filename", fspp::mode_t().addFileFlag(), fspp::uid_t(1000), fspp::gid_t(1000));
    this->setAccessTimestampBeforeYesterday("/mydir");
    auto operation = [&dir] () {
        dir->children();
    };
    this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAnyTimestamps});
}
*/

template<class ConcreteFileSystemTestFixture>
class FsppDirTest_Timestamps_Entries: public FsppNodeTest<ConcreteFileSystemTestFixture>, public TimestampTestUtils<ConcreteFileSystemTestFixture> {
public:

    void Test_givenNoatime_deleteChild() {
        this->setTimestampUpdateBehavior(fspp::noatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
            this->ExpectDoesntUpdateAccessTimestamp,
            this->ExpectUpdatesModificationTimestamp,
            this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenStrictatime_deleteChild() {
        this->setTimestampUpdateBehavior(fspp::strictatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenRelatime_deleteChild() {
        this->setTimestampUpdateBehavior(fspp::relatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenNodiratimeRelatime_deleteChild() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenNodiratimeStrictatime_deleteChild() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    /* TODO Re-enable this test once the root dir handles timestamps correctly
    void Test_givenNoatime_deleteChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::noatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenStrictatime_deleteChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::strictatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenRelatime_deleteChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::relatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenNodiratimeRelatime_deleteChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenNodiratimeStrictatime_deleteChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->remove();
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    */

    void Test_givenNoatime_renameChild() {
        this->setTimestampUpdateBehavior(fspp::noatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
            this->ExpectDoesntUpdateAccessTimestamp,
            this->ExpectUpdatesModificationTimestamp,
            this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenStrictatime_renameChild() {
        this->setTimestampUpdateBehavior(fspp::strictatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenRelatime_renameChild() {
        this->setTimestampUpdateBehavior(fspp::relatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenNodiratimeRelatime_renameChild() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenNodiratimeStrictatime_renameChild() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    /* TODO Re-enable this test once the root dir handles timestamps correctly
    void Test_givenNoatime_renameChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::noatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenStrictatime_renameChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::strictatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenRelatime_renameChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::relatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenNodiratimeRelatime_renameChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenNodiratimeStrictatime_renameChild_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        auto operation = [&child] () {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    */

    void Test_givenNoatime_moveChildIn() {
        this->setTimestampUpdateBehavior(fspp::noatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->CreateDir("/mydir");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
            this->ExpectDoesntUpdateAccessTimestamp,
            this->ExpectUpdatesModificationTimestamp,
            this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenStrictatime_moveChildIn() {
        this->setTimestampUpdateBehavior(fspp::strictatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->CreateDir("/mydir");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenRelatime_moveChildIn() {
        this->setTimestampUpdateBehavior(fspp::relatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->CreateDir("/mydir");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenNodiratimeRelatime_moveChildIn() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->CreateDir("/mydir");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenNodiratimeStrictatime_moveChildIn() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->CreateDir("/mydir");
        auto operation = [&child]() {
            child->rename("/mydir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    /* TODO Re-enable this test once the root dir handles timestamps correctly
    void Test_moveChildIn_givenNoatime_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::noatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->LoadDir("/");
        auto operation = [&child] () {
            child->rename("/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_moveChildIn_givenStrictatime_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::strictatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->LoadDir("/");
        auto operation = [&child] () {
            child->rename("/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_moveChildIn_givenRelatime_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::relatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->LoadDir("/");
        auto operation = [&child] () {
            child->rename("/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_moveChildIn_givenNodiratimeRelatime_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->LoadDir("/");
        auto operation = [&child] () {
            child->rename("/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_moveChildIn_givenNodiratimeStrictatime_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

        auto sourceDir = this->CreateDir("/sourcedir");
        auto child = this->CreateNode("/sourcedir/childname");
        auto dir = this->LoadDir("/");
        auto operation = [&child] () {
            child->rename("/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    */

    void Test_givenNoatime_moveChildOut() {
        this->setTimestampUpdateBehavior(fspp::noatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child]() {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
            this->ExpectDoesntUpdateAccessTimestamp,
            this->ExpectUpdatesModificationTimestamp,
            this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenStrictatime_moveChildOut() {
        this->setTimestampUpdateBehavior(fspp::strictatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child]() {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenRelatime_moveChildOut() {
        this->setTimestampUpdateBehavior(fspp::relatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child]() {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenNodiratimeRelatime_moveChildOut() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child]() {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    void Test_givenNodiratimeStrictatime_moveChildOut() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

        auto dir = this->CreateDir("/mydir");
        auto child = this->CreateNode("/mydir/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child]() {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/mydir", operation, {
                this->ExpectDoesntUpdateAccessTimestamp,
                this->ExpectUpdatesModificationTimestamp,
                this->ExpectUpdatesMetadataTimestamp
        });
    }

    /* TODO Re-enable this test once the root dir handles timestamps correctly
    void Test_givenNoatime_moveChildOut_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::noatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child] () {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenStrictatime_moveChildOut_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::strictatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child] () {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenRelatime_moveChildOut_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::relatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child] () {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenNodiratimeRelatime_moveChildOut_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_relatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child] () {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    void Test_givenNodiratimeStrictatime_moveChildOut_inRootDir() {
        this->setTimestampUpdateBehavior(fspp::nodiratime_strictatime());

        auto dir = this->LoadDir("/");
        auto child = this->CreateNode("/childname");
        this->CreateDir("/targetdir");
        auto operation = [&child] () {
            child->rename("/targetdir/mychild");
        };
        this->EXPECT_OPERATION_UPDATES_TIMESTAMPS_AS("/", operation, {this->ExpectDoesntUpdateAccessTimestamp, this->ExpectUpdatesModificationTimestamp, this->ExpectUpdatesMetadataTimestamp});
    }
    */
};

REGISTER_TYPED_TEST_CASE_P(FsppDirTest_Timestamps_1,
   givenNoatime_createAndOpenFile,
   givenStrictatime_createAndOpenFile,
   givenRelatime_createAndOpenFile,
   givenNodiratimeRelatime_createAndOpenFile,
   givenNodiratimeStrictatime_createAndOpenFile,
   givenNoatime_createAndOpenFile_TimestampsOfCreatedFile,
   givenStrictatime_createAndOpenFile_TimestampsOfCreatedFile,
   givenRelatime_createAndOpenFile_TimestampsOfCreatedFile,
   givenNodiratimeRelatime_createAndOpenFile_TimestampsOfCreatedFile,
   givenNodiratimeStrictatime_createAndOpenFile_TimestampsOfCreatedFile,
   givenNoatime_createDir,
   givenStrictatime_createDir,
   givenRelatime_createDir,
   givenNodiratimeRelatime_createDir,
   givenNodiratimeStrictatime_createDir,
   givenNoatime_createDir_TimestampsOfCreatedDir,
   givenStrictatime_createDir_TimestampsOfCreatedDir,
   givenRelatime_createDir_TimestampsOfCreatedDir,
   givenNodiratimeRelatime_createDir_TimestampsOfCreatedDir,
   givenNodiratimeStrictatime_createDir_TimestampsOfCreatedDir,
   givenNoatime_createSymlink,
   givenStrictatime_createSymlink,
   givenRelatime_createSymlink,
   givenNodiratimeRelatime_createSymlink,
   givenNodiratimeStrictatime_createSymlink,
   givenNoatime_createSymlink_TimestampsOfCreatedSymlink,
   givenStrictatime_createSymlink_TimestampsOfCreatedSymlink,
   givenRelatime_createSymlink_TimestampsOfCreatedSymlink,
   givenNodiratimeRelatime_createSymlink_TimestampsOfCreatedSymlink,
   givenNodiratimeStrictatime_createSymlink_TimestampsOfCreatedSymlink
);
REGISTER_TYPED_TEST_CASE_P(FsppDirTest_Timestamps_2,
   givenNoatime_withAtimeNewerThanMtime_children_empty,
   givenNoatime_withAtimeOlderThanMtime_children_empty,
   givenNoatime_withAtimeBeforeYesterday_children_empty,
   givenStrictatime_withAtimeNewerThanMtime_children_empty,
   givenStrictatime_withAtimeOlderThanMtime_children_empty,
   givenStrictatime_withAtimeBeforeYesterday_children_empty,
   givenRelatime_withAtimeNewerThanMtime_children_empty,
   givenRelatime_withAtimeOlderThanMtime_children_empty,
   givenRelatime_withAtimeBeforeYesterday_children_empty,
   givenNodiratimeRelatime_withAtimeNewerThanMtime_children_empty,
   givenNodiratimeRelatime_withAtimeOlderThanMtime_children_empty,
   givenNodiratimeRelatime_withAtimeBeforeYesterday_children_empty,
   givenNodiratimeStrictatime_withAtimeNewerThanMtime_children_empty,
   givenNodiratimeStrictatime_withAtimeOlderThanMtime_children_empty,
   givenNodiratimeStrictatime_withAtimeBeforeYesterday_children_empty,
   givenNoatime_withAtimeNewerThanMtime_children_nonempty,
   givenNoatime_withAtimeOlderThanMtime_children_nonempty,
   givenNoatime_withAtimeBeforeYesterday_children_nonempty,
   givenStrictatime_withAtimeNewerThanMtime_children_nonempty,
   givenStrictatime_withAtimeOlderThanMtime_children_nonempty,
   givenStrictatime_withAtimeBeforeYesterday_children_nonempty,
   givenRelatime_withAtimeNewerThanMtime_children_nonempty,
   givenRelatime_withAtimeOlderThanMtime_children_nonempty,
   givenRelatime_withAtimeBeforeYesterday_children_nonempty,
   givenNodiratimeRelatime_withAtimeNewerThanMtime_children_nonempty,
   givenNodiratimeRelatime_withAtimeOlderThanMtime_children_nonempty,
   givenNodiratimeRelatime_withAtimeBeforeYesterday_children_nonempty,
   givenNodiratimeStrictatime_withAtimeNewerThanMtime_children_nonempty,
   givenNodiratimeStrictatime_withAtimeOlderThanMtime_children_nonempty,
   givenNodiratimeStrictatime_withAtimeBeforeYesterday_children_nonempty
);

REGISTER_NODE_TEST_CASE(FsppDirTest_Timestamps_Entries,
   givenNoatime_deleteChild,
   givenStrictatime_deleteChild,
   givenRelatime_deleteChild,
   givenNodiratimeRelatime_deleteChild,
   givenNodiratimeStrictatime_deleteChild,
   givenNoatime_renameChild,
   givenStrictatime_renameChild,
   givenRelatime_renameChild,
   givenNodiratimeRelatime_renameChild,
   givenNodiratimeStrictatime_renameChild,
   givenNoatime_moveChildIn,
   givenStrictatime_moveChildIn,
   givenRelatime_moveChildIn,
   givenNodiratimeRelatime_moveChildIn,
   givenNodiratimeStrictatime_moveChildIn,
   givenNoatime_moveChildOut,
   givenStrictatime_moveChildOut,
   givenRelatime_moveChildOut,
   givenNodiratimeRelatime_moveChildOut,
   givenNodiratimeStrictatime_moveChildOut
);

#endif
