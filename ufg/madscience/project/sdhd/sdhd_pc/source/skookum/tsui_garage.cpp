// File Line: 32
// RVA: 0x4D78C0
void UFG::TSUI_Garage::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Garage");
  SSClass::register_method_func(v0, "selection_made", UFG::TSUI_Garage::MthdC_selection_made, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "should_skip_customization",
    UFG::TSUI_Garage::MthdC_should_skip_customization,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "add_vehicle_order_override",
    UFG::TSUI_Garage::MthdC_add_vehicle_order_override,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "clear_vehicle_order_override",
    UFG::TSUI_Garage::MthdC_clear_vehicle_order_override,
    1,
    rebindc);
}

// File Line: 43
// RVA: 0x4ECF00
void __fastcall UFG::TSUI_Garage::MthdC_selection_made(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  *ppResult = SSBoolean::pool_new(!UFG::UIHKScreenGarageBrowser::mPlayerBackedOut);
}

// File Line: 49
// RVA: 0x4EF820
void __fastcall UFG::TSUI_Garage::MthdC_should_skip_customization(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  *ppResult = SSBoolean::pool_new(UFG::UIHKScreenGarageBrowser::mSkipCustomization);
}

// File Line: 55
// RVA: 0x4E3350
void __fastcall UFG::TSUI_Garage::MthdC_add_vehicle_order_override(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qSymbol spawnInfo; // [rsp+30h] [rbp+8h] BYREF

  spawnInfo.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::UIHKScreenGarageBrowser::AddVehicleOrderOverride(&spawnInfo);
}

// File Line: 63
// RVA: 0x4E46A0
// attributes: thunk
void __fastcall UFG::TSUI_Garage::MthdC_clear_vehicle_order_override(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenGarageBrowser::ClearVehicleOrderOverride();
}

