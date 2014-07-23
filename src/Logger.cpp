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
    #include <boost/log/utility/setup/console.hpp>
    #include <boost/log/utility/setup/file.hpp>
    #include <boost/log/utility/setup/common_attributes.hpp>
    #include <boost/log/sources/severity_logger.hpp>
    #include <boost/log/sources/record_ostream.hpp>
    #include <boost/log/support/date_time.hpp>
#pragma clang diagnostic pop

using namespace ci;

namespace Cinder { namespace Logger {

#define CINDER_LOG(logger, level) \
    BOOST_LOG_STREAM_WITH_PARAMS(logger, (boost::log::keywords::severity = static_cast<boost::log::trivial::severity_level>(level)))

#define CINDER_LOG_TRIVIAL(level) \
    CINDER_LOG(boost::log::trivial::logger::get(), level)

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

LoggerRef Logger::create() {
    return LoggerRef(new Logger())->shared_from_this();
}

Logger::Logger() {
    setSeverityLevel(SeverityLevel::Info);
    logging::add_common_attributes();

    logging::add_console_log(
        std::cout,
        keywords::format = (
            expr::stream
                << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S")
                << ": <" << logging::trivial::severity
                << "> " << expr::smessage
        )
    );
}

Logger::~Logger() {
}

#pragma mark -

void Logger::setSeverityLevel(SeverityLevel level) {
    mSeverityLevel = level;
    logging::core::get()->set_filter(logging::trivial::severity >= static_cast<boost::log::trivial::severity_level>(mSeverityLevel));
}

void Logger::setLogFilePath(const fs::path& path) {
    // TODO - replace existing when necessary
    mLogFilePath = path;

    logging::add_file_log(
        keywords::file_name = mLogFilePath,
        keywords::format = (
            expr::stream
                << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S")
                << ": <" << logging::trivial::severity
                << "> " << expr::smessage
        ),
        keywords::auto_flush = true
    );
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
