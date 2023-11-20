// File Line: 301
// RVA: 0x15B950
void __fastcall AK::IAkPluginParam::~IAkPluginParam(AK::IAkPluginParam *this)
{
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkPluginParam::`vftable';
  this->vfptr = (AK::IAkRTPCSubscriberVtbl *)&AK::IAkRTPCSubscriber::`vftable';
}

// File Line: 372
// RVA: 0x15BE70
void __fastcall AK::IAkPlugin::~IAkPlugin(AK::IAkPlugin *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

// File Line: 548
// RVA: 0x15BE80
void __fastcall AK::IAkSourcePlugin::~IAkSourcePlugin(AK::IAkSourcePlugin *this)
{
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkSourcePlugin::`vftable';
  this->vfptr = (AK::IAkPluginVtbl *)&AK::IAkPlugin::`vftable';
}

