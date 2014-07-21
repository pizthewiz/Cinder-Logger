//
//  Logger.cpp
//  Cinder-Logger
//
//  Created by Jean-Pierre Mouilleseaux on 09 Apr 2014.
//  Copyright 2014 Chorded Constructions. All rights reserved.
//

#include "Logger.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-register"
    #include <boost/log/core.hpp>
    #include <boost/log/trivial.hpp>
    #include <boost/log/expressions.hpp>
    #include <boost/log/sinks/text_file_backend.hpp>
    #include <boost/log/utility/setup/file.hpp>
    #include <boost/log/utility/setup/common_attributes.hpp>
    #include <boost/log/sources/severity_logger.hpp>
    #include <boost/log/sources/record_ostream.hpp>
#pragma clang diagnostic pop

using namespace ci;

namespace Cinder { namespace Logger {

#define CINDER_LOG(logger, level) \
    BOOST_LOG_STREAM_WITH_PARAMS(logger, (boost::log::keywords::severity = static_cast<boost::log::trivial::severity_level>(level)))

#define CINDER_LOG_TRIVIAL(level) \
    CINDER_LOG(boost::log::trivial::logger::get(), level)

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;

LoggerRef Logger::create() {
    return LoggerRef(new Logger())->shared_from_this();
}

Logger::Logger() {
    setSeverityLevel(SeverityLevel::Info);
}

Logger::~Logger() {
}

#pragma mark -

void Logger::setSeverityLevel(SeverityLevel level) {
    if (level == mSeverityLevel) {
        return;
    }

    mSeverityLevel = level;
    logging::core::get()->set_filter(logging::trivial::severity >= static_cast<boost::log::trivial::severity_level>(mSeverityLevel));
}

void Logger::setLogFilePath(const boost::filesystem::path& path) {
    mLogFilePath = path;
    // TODO - replace existing
    logging::add_file_log(mLogFilePath);
}

#pragma mark -

void Logger::logMessage(SeverityLevel level, const std::string& message) {
    CINDER_LOG_TRIVIAL(level) << message;
}

void Logger::logTrace(const std::string& message) {
    CINDER_LOG_TRIVIAL(SeverityLevel::Trace) << message;
}

void Logger::logDebug(const std::string& message) {
    CINDER_LOG_TRIVIAL(SeverityLevel::Debug) << message;
}

void Logger::logInfo(const std::string& message) {
    CINDER_LOG_TRIVIAL(SeverityLevel::Info) << message;
}

void Logger::logWarning(const std::string& message) {
    CINDER_LOG_TRIVIAL(SeverityLevel::Warning) << message;
}

void Logger::logError(const std::string& message) {
    CINDER_LOG_TRIVIAL(SeverityLevel::Error) << message;
}

void Logger::logFatal(const std::string& message) {
    CINDER_LOG_TRIVIAL(SeverityLevel::Fatal) << message;
}

}}
