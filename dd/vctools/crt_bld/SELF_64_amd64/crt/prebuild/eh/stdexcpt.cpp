// File Line: 52
// RVA: 0x12B0D0C
void __fastcall std::bad_cast::bad_cast(std::bad_cast *this, const char *_Message)
{
  std::bad_cast *v2; // rbx
  char *_What; // [rsp+38h] [rbp+10h]

  _What = (char *)_Message;
  v2 = this;
  std::exception::exception((std::exception *)&this->vfptr, (const char *const *)&_What);
  v2->vfptr = (std::exceptionVtbl *)&std::bad_cast::`vftable;
}

// File Line: 57
// RVA: 0x12B0CE8
void __fastcall std::bad_cast::bad_cast(std::bad_cast *this, std::bad_cast *that)
{
  std::bad_cast *v2; // rbx

  v2 = this;
  std::exception::exception((std::exception *)&this->vfptr, (std::exception *)&that->vfptr);
  v2->vfptr = (std::exceptionVtbl *)&std::bad_cast::`vftable;
}

// File Line: 87
// RVA: 0x12B0D5C
void __fastcall std::bad_typeid::bad_typeid(std::bad_typeid *this, const char *_Message)
{
  std::bad_typeid *v2; // rbx
  char *_What; // [rsp+38h] [rbp+10h]

  _What = (char *)_Message;
  v2 = this;
  std::exception::exception((std::exception *)&this->vfptr, (const char *const *)&_What);
  v2->vfptr = (std::exceptionVtbl *)&std::bad_typeid::`vftable;
}

// File Line: 92
// RVA: 0x12B0D38
void __fastcall std::bad_typeid::bad_typeid(std::bad_typeid *this, std::bad_typeid *that)
{
  std::bad_typeid *v2; // rbx

  v2 = this;
  std::exception::exception((std::exception *)&this->vfptr, (std::exception *)&that->vfptr);
  v2->vfptr = (std::exceptionVtbl *)&std::bad_typeid::`vftable;
}

// File Line: 106
// RVA: 0x12B0CC4
void __fastcall std::__non_rtti_object::__non_rtti_object(std::__non_rtti_object *this, const char *_Message)
{
  std::__non_rtti_object *v2; // rbx

  v2 = this;
  std::bad_typeid::bad_typeid((std::bad_typeid *)&this->vfptr, _Message);
  v2->vfptr = (std::exceptionVtbl *)&std::__non_rtti_object::`vftable;
}

// File Line: 111
// RVA: 0x12B0CA0
void __fastcall std::__non_rtti_object::__non_rtti_object(std::__non_rtti_object *this, std::__non_rtti_object *that)
{
  std::__non_rtti_object *v2; // rbx

  v2 = this;
  std::exception::exception((std::exception *)&this->vfptr, (std::exception *)&that->vfptr);
  v2->vfptr = (std::exceptionVtbl *)&std::__non_rtti_object::`vftable;
}

// File Line: 115
// RVA: 0x12B0E00
void __fastcall std::bad_cast::~bad_cast(std::exception *this)
{
  this->vfptr = (std::exceptionVtbl *)&std::exception::`vftable;
  std::exception::_Tidy(this);
}

