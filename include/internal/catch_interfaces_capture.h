/*
 *  Created by Phil on 07/01/2011.
 *  Copyright 2011 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_INTERFACES_CAPTURE_H_INCLUDED
#define TWOBLUECUBES_CATCH_INTERFACES_CAPTURE_H_INCLUDED

#include <string>
#include "catch_result_type.h"
#include "catch_common.h"

namespace Catch {

    class TestCase;
    class AssertionResult;

    struct AssertionInfo;
    struct SectionInfo;
    struct SectionEndInfo;
    struct MessageInfo;
    struct Counts;
    struct IConfig;

    struct IRunContext {

        virtual ~IRunContext();

        virtual void assertionEnded( AssertionResult const& result ) = 0;
        
        virtual bool sectionStarted(    SectionInfo const& sectionInfo,
                                        Counts& assertions ) = 0;
        virtual void sectionEnded( SectionEndInfo const& endInfo ) = 0;
        virtual void sectionEndedEarly( SectionEndInfo const& endInfo ) = 0;
        
        virtual void pushScopedMessage( MessageInfo const& message ) = 0;
        virtual void popScopedMessage( MessageInfo const& message ) = 0;

        virtual void handleFatalErrorCondition( std::string const& message ) = 0;
        
        virtual std::string getCurrentTestName() const = 0;
        virtual AssertionResult const* getLastResult() const = 0;
        virtual bool isAborting() const = 0;
        
        virtual IConfig const& config() const = 0;
    };

    IRunContext& getCurrentRunContext();
    
    IConfig const* getCurrentConfig();

    class LocalContext {

    public:
        IRunContext& operator()() const {
            return getCurrentRunContext(); // !TBD
        }
    };
}

inline Catch::IRunContext& C_A_T_C_H_Context() {
    return Catch::getCurrentRunContext();
}

#endif // TWOBLUECUBES_CATCH_INTERFACES_CAPTURE_H_INCLUDED
