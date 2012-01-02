#ifndef _ACCESSORS_H_
#define _ACCESSORS_H_

#define READER(type, name)                       \
type get_##name(){ return name; };

#define WRITER(type, name)                       \
void set_##name(type* _##name){name = _##name; };

#define ACCESSOR(type, name)                     \
type get_##name(){ return name; };               \
void set_##name(type local_##name){name = local_##name; };

#endif // _ACCESSORS_H_