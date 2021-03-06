#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptObject.h"

namespace bs
{
	class AnimationUtility;

	class BS_SCR_BE_EXPORT ScriptAnimationUtility : public ScriptObject<ScriptAnimationUtility>
	{
	public:
		SCRIPT_OBJ(ENGINE_ASSEMBLY, "BansheeEngine", "AnimationUtility")

		ScriptAnimationUtility(MonoObject* managedInstance, const SPtr<AnimationUtility>& value);

		SPtr<AnimationUtility> getInternal() const { return mInternal; }
		static MonoObject* create(const SPtr<AnimationUtility>& value);

	private:
		SPtr<AnimationUtility> mInternal;

		static MonoObject* Internal_eulerToQuaternionCurve(MonoObject* eulerCurve);
		static MonoObject* Internal_quaternionToEulerCurve(MonoObject* quatCurve);
		static MonoArray* Internal_splitCurve3D(MonoObject* compoundCurve);
		static MonoObject* Internal_combineCurve3D(MonoArray* curveComponents);
		static MonoArray* Internal_splitCurve2D(MonoObject* compoundCurve);
		static MonoObject* Internal_combineCurve2D(MonoArray* curveComponents);
		static void Internal_calculateRange(MonoArray* curves, float* xMin, float* xMax, float* yMin, float* yMax);
	};
}
