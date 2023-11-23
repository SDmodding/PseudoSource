// File Line: 15
// RVA: 0x146DB80
__int64 UFG::Editor::_dynamic_initializer_for__gUndoChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::Editor::gUndoChannel, 0x23DF27A9u, 0i64, 0i64);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gUndoChannel__);
}

// File Line: 16
// RVA: 0x146DAA0
__int64 UFG::Editor::_dynamic_initializer_for__gRedoChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::Editor::gRedoChannel, 0x23C51C72u, 0i64, 0i64);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gRedoChannel__);
}

// File Line: 18
// RVA: 0x146E5C0
__int64 UFG::Editor::_dynamic_initializer_for__gsymXformLocal__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("XformLocal", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymXformLocal, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymXformLocal__);
}

// File Line: 19
// RVA: 0x146E600
__int64 UFG::Editor::_dynamic_initializer_for__gsymXformParent__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("XformParent", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymXformParent, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymXformParent__);
}

// File Line: 20
// RVA: 0x146E240
__int64 UFG::Editor::_dynamic_initializer_for__gsymNameRoot__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("NameRoot", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymNameRoot, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymNameRoot__);
}

// File Line: 21
// RVA: 0x146E280
__int64 UFG::Editor::_dynamic_initializer_for__gsymObjectType__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ObjectType", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymObjectType, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymObjectType__);
}

// File Line: 22
// RVA: 0x146E400
__int64 UFG::Editor::_dynamic_initializer_for__gsymSimObjChildren__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SimObjChildren", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymSimObjChildren, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymSimObjChildren__);
}

// File Line: 23
// RVA: 0x146E180
__int64 UFG::Editor::_dynamic_initializer_for__gsymLinks__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Links", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymLinks, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymLinks__);
}

// File Line: 24
// RVA: 0x146E140
__int64 UFG::Editor::_dynamic_initializer_for__gsymLinkParam__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("LinkParam", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymLinkParam, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymLinkParam__);
}

// File Line: 25
// RVA: 0x146E0C0
__int64 UFG::Editor::_dynamic_initializer_for__gsymLinkEntity__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("LinkEntity", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymLinkEntity, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymLinkEntity__);
}

// File Line: 26
// RVA: 0x146E100
__int64 UFG::Editor::_dynamic_initializer_for__gsymLinkObjective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("LinkObjective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymLinkObjective, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymLinkObjective__);
}

// File Line: 27
// RVA: 0x146DD80
__int64 UFG::Editor::_dynamic_initializer_for__gsymDefaultComponentRegion__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-component-Region", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymDefaultComponentRegion, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDefaultComponentRegion__);
}

// File Line: 28
// RVA: 0x146DD00
__int64 UFG::Editor::_dynamic_initializer_for__gsymDefaultComponentCameraMarker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-component-CameraMarker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymDefaultComponentCameraMarker, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDefaultComponentCameraMarker__);
}

// File Line: 29
// RVA: 0x146DD40
__int64 UFG::Editor::_dynamic_initializer_for__gsymDefaultComponentIrrVol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("component_IrradianceVolume", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymDefaultComponentIrrVol, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDefaultComponentIrrVol__);
}

// File Line: 30
// RVA: 0x146DFC0
__int64 UFG::Editor::_dynamic_initializer_for__gsymFXSimComponent__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("FXSimComponent", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymFXSimComponent, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymFXSimComponent__);
}

// File Line: 31
// RVA: 0x146E540
__int64 UFG::Editor::_dynamic_initializer_for__gsymType__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Type", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymType, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymType__);
}

// File Line: 32
// RVA: 0x146E200
__int64 UFG::Editor::_dynamic_initializer_for__gsymMin__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Min", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymMin, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymMin__);
}

// File Line: 33
// RVA: 0x146E1C0
__int64 UFG::Editor::_dynamic_initializer_for__gsymMax__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Max", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymMax, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymMax__);
}

// File Line: 34
// RVA: 0x146E3C0
__int64 UFG::Editor::_dynamic_initializer_for__gsymRadius__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Radius", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymRadius, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymRadius__);
}

// File Line: 35
// RVA: 0x146DC80
__int64 UFG::Editor::_dynamic_initializer_for__gsymBoxMin__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Min", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymBoxMin, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymBoxMin__);
}

// File Line: 36
// RVA: 0x146DC40
__int64 UFG::Editor::_dynamic_initializer_for__gsymBoxMax__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Max", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymBoxMax, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymBoxMax__);
}

// File Line: 37
// RVA: 0x146DF40
__int64 UFG::Editor::_dynamic_initializer_for__gsymExtentAbove__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ExtentAbove", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymExtentAbove, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymExtentAbove__);
}

// File Line: 38
// RVA: 0x146DF80
__int64 UFG::Editor::_dynamic_initializer_for__gsymExtentBelow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ExtentBelow", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymExtentBelow, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymExtentBelow__);
}

// File Line: 39
// RVA: 0x146E580
__int64 UFG::Editor::_dynamic_initializer_for__gsymVertexes__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Vertexes", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymVertexes, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymVertexes__);
}

// File Line: 40
// RVA: 0x146E300
__int64 UFG::Editor::_dynamic_initializer_for__gsymPlaneNear__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PlaneNear", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymPlaneNear, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymPlaneNear__);
}

// File Line: 41
// RVA: 0x146E2C0
__int64 UFG::Editor::_dynamic_initializer_for__gsymPlaneFar__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PlaneFar", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymPlaneFar, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymPlaneFar__);
}

// File Line: 42
// RVA: 0x146E000
__int64 UFG::Editor::_dynamic_initializer_for__gsymFovH__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("FovH", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymFovH, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymFovH__);
}

// File Line: 43
// RVA: 0x146DE40
__int64 UFG::Editor::_dynamic_initializer_for__gsymDofFocalDist__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DofFocalDist", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymDofFocalDist, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDofFocalDist__);
}

// File Line: 44
// RVA: 0x146DE80
__int64 UFG::Editor::_dynamic_initializer_for__gsymDofInFocusRange__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DofInFocusRange", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymDofInFocusRange, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDofInFocusRange__);
}

// File Line: 45
// RVA: 0x146DF00
__int64 UFG::Editor::_dynamic_initializer_for__gsymDofNearRange__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DofNearRange", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymDofNearRange, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDofNearRange__);
}

// File Line: 46
// RVA: 0x146DEC0
__int64 UFG::Editor::_dynamic_initializer_for__gsymDofNearBlurRadius__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DofNearBlurRadius", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymDofNearBlurRadius, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDofNearBlurRadius__);
}

// File Line: 47
// RVA: 0x146DE00
__int64 UFG::Editor::_dynamic_initializer_for__gsymDofFarRange__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DofFarRange", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymDofFarRange, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDofFarRange__);
}

// File Line: 48
// RVA: 0x146DDC0
__int64 UFG::Editor::_dynamic_initializer_for__gsymDofFarBlurRadius__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DofFarBlurRadius", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymDofFarBlurRadius, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymDofFarBlurRadius__);
}

// File Line: 49
// RVA: 0x146DCC0
__int64 UFG::Editor::_dynamic_initializer_for__gsymCreateObjectFlags__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("CreateObjectFlags", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymCreateObjectFlags, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymCreateObjectFlags__);
}

// File Line: 50
// RVA: 0x146E440
__int64 UFG::Editor::_dynamic_initializer_for__gsymSkookum_c_sel_guy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("c_sel_guy", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymSkookum_c_sel_guy, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymSkookum_c_sel_guy__);
}

// File Line: 51
// RVA: 0x146E480
__int64 UFG::Editor::_dynamic_initializer_for__gsymSkookum_c_sel_guy_prev__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("c_sel_guy_prev", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymSkookum_c_sel_guy_prev, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymSkookum_c_sel_guy_prev__);
}

// File Line: 52
// RVA: 0x146E4C0
__int64 UFG::Editor::_dynamic_initializer_for__gsymSkookum_c_selected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("c_selected", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymSkookum_c_selected, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymSkookum_c_selected__);
}

// File Line: 53
// RVA: 0x146E500
__int64 UFG::Editor::_dynamic_initializer_for__gsymSkookum_c_selected_prev__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("c_selected_prev", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymSkookum_c_selected_prev, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymSkookum_c_selected_prev__);
}

// File Line: 54
// RVA: 0x146E340
__int64 UFG::Editor::_dynamic_initializer_for__gsymPrefabId__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PrefabId", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymPrefabId, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymPrefabId__);
}

// File Line: 55
// RVA: 0x146E380
__int64 UFG::Editor::_dynamic_initializer_for__gsymPrefab_SceneObjects__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Prefab_SceneObjects", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymPrefab_SceneObjects, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymPrefab_SceneObjects__);
}

// File Line: 56
// RVA: 0x146E080
__int64 UFG::Editor::_dynamic_initializer_for__gsymIrrVolMin__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IrrVol_Min", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymIrrVolMin, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymIrrVolMin__);
}

// File Line: 57
// RVA: 0x146E040
__int64 UFG::Editor::_dynamic_initializer_for__gsymIrrVolMax__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IrrVol_Max", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::gsymIrrVolMax, v0);
  return atexit((int (__fastcall *)())UFG::Editor::_dynamic_atexit_destructor_for__gsymIrrVolMax__);
}

