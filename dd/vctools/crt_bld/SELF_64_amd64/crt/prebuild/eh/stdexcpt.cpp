// File Line: 52
// RVA: 0x12B0D0C
void __fastcall std::bad_cast::bad_cast(std::bad_cast *this, char *_Message)
{
  char *_What; // [rsp+38h] [rbp+10h] BYREF

  _What = _Message;
  std::exception::exception(this, (const char *const *)&_What);
  this->vfptr = (std::exceptionVtbl *)&std::bad_cast::`vftable;
}

// File Line: 57
// RVA: 0x12B0CE8
void __fastcall std::bad_cast::bad_cast(std::bad_cast *this, std::bad_cast *that)
{
  std::exception::exception(this, that);
  this->vfptr = (std::exceptionVtbl *)&std::bad_cast::`vftable;
}

// File Line: 87
// RVA: 0x12B0D5C
void __fastcall std::bad_typeid::bad_typeid(std::bad_typeid *this, char *_Message)
{
  char *_What; // [rsp+38h] [rbp+10h] BYREF

  _What = _Message;
  std::exception::exception(this, (const char *const *)&_What);
  this->vfptr = (std::exceptionVtbl *)&std::bad_typeid::`vftable;
}

// File Line: 92
// RVA: 0x12B0D38
void __fastcall std::bad_typeid::bad_typeid(std::bad_typeid *this, std::bad_typeid *that)
{
  std::exception::exception(this, that);
  this->vfptr = (std::exceptionVtbl *)&std::bad_typeid::`vftable;
}

// File Line: 106
// RVA: 0x12B0CC4
void __fastcall std::__non_rtti_object::__non_rtti_object(std::__non_rtti_object *this, const char *_Message)
{
  std::bad_typeid::bad_typeid(this, _Message);
  this->vfptr = (std::exceptionVtbl *)&std::__non_rtti_object::`vftable;
}

// File Line: 111
// RVA: 0x12B0CA0
void __fastcall std::__non_rtti_object::__non_rtti_object(std::__non_rtti_object *this, std::__non_rtti_object *that)
{
  std::exception::exception(this, that);
  this->vfptr = (std::exceptionVtbl *)&std::__non_rtti_object::`vftable;
}

// File Line: 115
// RVA: 0x12B0E00
void __fastcall std::bad_cast::~bad_cast(std::exception *this)
{
  this->vfptr = (std::exceptionVtbl *)&std::exception::`vftable;
  std::exception::_Tidy(this);
}

