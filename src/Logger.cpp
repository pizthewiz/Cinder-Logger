//
//  Logger.cpp
//  Cinder-Logger
//
//  Created by Jean-Pierre Mouilleseaux on 09 Apr 2014.
//  Copyright 2014 Chorded Constructions. All rights reserved.
//

#include "Logger.h"

#include "cinder/Utilities.h"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

using namespace ci;

namespace Cinder { namespace Logger {

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

LoggerRef Logger::create() {
    return LoggerRef(new Logger())->shared_from_this();
}

Logger::Logger() {
    setSeverityLevel(SeverityLevelInfo);
}

Logger::~Logger() {
}

#pragma mark -

void Logger::setSeverityLevel(SeverityLevel level) {
    if (level == mSeverityLevel) {
        return;
    }

    mSeverityLevel = level;
    logging::core::get()->set_filter(logging::trivial::severity >= mSeverityLevel);
}

void Logger::setLogFilePath(const boost::filesystem::path path) {
    mLogFilePath = path;
    // TODO - replace existing
    logging::add_file_log(mLogFilePath);
}

boost::filesystem::path Logger::getLogFilePath() const {
    return mLogFilePath;
}

#pragma mark -

void Logger::LogMessage(SeverityLevel level, const std::string& message) {
    switch (level) {
        case SeverityLevelTrace:
            LogTrace(message);
            break;
        case SeverityLevelDebug:
            LogDebug(message);
            break;
        case SeverityLevelInfo:
            LogInfo(message);
            break;
        case SeverityLevelWarning:
            LogWarning(message);
            break;
        case SeverityLevelError:
            LogError(message);
            break;
        case SeverityLevelFatal:
            LogFatal(message);
            break;
        default:
            break;
    }
}

void Logger::LogTrace(const std::string& message) {
    BOOST_LOG_TRIVIAL(trace) << message;
}

void Logger::LogDebug(const std::string& message) {
    BOOST_LOG_TRIVIAL(debug) << message;
}

void Logger::LogInfo(const std::string& message) {
    BOOST_LOG_TRIVIAL(info) << message;
}

void Logger::LogWarning(const std::string& message) {
    BOOST_LOG_TRIVIAL(warning) << message;
}

void Logger::LogError(const std::string& message) {
    BOOST_LOG_TRIVIAL(error) << message;
}

void Logger::LogFatal(const std::string& message) {
    BOOST_LOG_TRIVIAL(fatal) << message;
}

}}
