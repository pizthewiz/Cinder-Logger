//
//  Logger.cpp
//  Cinder-Logger
//
//  Created by Jean-Pierre Mouilleseaux on 09 Apr 2014.
//  Copyright 2014 Chorded Constructions. All rights reserved.
//

#include "Logger.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace Cinder { namespace Logger {

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
    mSeverityLevel = level;
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= mSeverityLevel);
}

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
