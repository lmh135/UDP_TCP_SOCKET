# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from lidar_msgs/LaserPacket.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class LaserPacket(genpy.Message):
  _md5sum = "61992e7cac699d037e7a874f2eedcf02"
  _type = "lidar_msgs/LaserPacket"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float32[12] Azimuth
float32[192] distance
uint64 timestamp
uint64 id_num
"""
  __slots__ = ['Azimuth','distance','timestamp','id_num']
  _slot_types = ['float32[12]','float32[192]','uint64','uint64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       Azimuth,distance,timestamp,id_num

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LaserPacket, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.Azimuth is None:
        self.Azimuth = [0.] * 12
      if self.distance is None:
        self.distance = [0.] * 192
      if self.timestamp is None:
        self.timestamp = 0
      if self.id_num is None:
        self.id_num = 0
    else:
      self.Azimuth = [0.] * 12
      self.distance = [0.] * 192
      self.timestamp = 0
      self.id_num = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_get_struct_12f().pack(*self.Azimuth))
      buff.write(_get_struct_192f().pack(*self.distance))
      _x = self
      buff.write(_get_struct_2Q().pack(_x.timestamp, _x.id_num))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 48
      self.Azimuth = _get_struct_12f().unpack(str[start:end])
      start = end
      end += 768
      self.distance = _get_struct_192f().unpack(str[start:end])
      _x = self
      start = end
      end += 16
      (_x.timestamp, _x.id_num,) = _get_struct_2Q().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(self.Azimuth.tostring())
      buff.write(self.distance.tostring())
      _x = self
      buff.write(_get_struct_2Q().pack(_x.timestamp, _x.id_num))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 48
      self.Azimuth = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=12)
      start = end
      end += 768
      self.distance = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=192)
      _x = self
      start = end
      end += 16
      (_x.timestamp, _x.id_num,) = _get_struct_2Q().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_192f = None
def _get_struct_192f():
    global _struct_192f
    if _struct_192f is None:
        _struct_192f = struct.Struct("<192f")
    return _struct_192f
_struct_12f = None
def _get_struct_12f():
    global _struct_12f
    if _struct_12f is None:
        _struct_12f = struct.Struct("<12f")
    return _struct_12f
_struct_2Q = None
def _get_struct_2Q():
    global _struct_2Q
    if _struct_2Q is None:
        _struct_2Q = struct.Struct("<2Q")
    return _struct_2Q
