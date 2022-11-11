#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/DriveDistance.h"
#include "commands/TurnDegrees.h"
#include "subsystems/Drivetrain.h"

class AutoTest
        : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutoTest> {
    public:
     explicit AutoTest(Drivetrain* drive) {
         AddCommands(
             DriveDistance(-0.5, 3_m, drive), TurnDegrees(-0.5, 180_deg, drive),
             DriveDistance(-0.5, 3_m, drive), TurnDegrees(0.5, 180_deg, drive));
     }
};