#pragma once

// Approximate kanata's tap-hold-release with tap-time/hold-time 200.
#undef TAPPING_TERM
#define TAPPING_TERM 200
// Hold when another key is pressed and released while the tap-hold is down.
#define PERMISSIVE_HOLD
// Don't pick the hold just because another key was pressed (fast rolls).
#define IGNORE_MOD_TAP_INTERRUPT
