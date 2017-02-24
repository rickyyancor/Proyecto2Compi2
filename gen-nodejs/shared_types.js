//
// Autogenerated by Thrift Compiler (0.9.0)
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//
var Thrift = require('thrift').Thrift;
var ttypes = module.exports = {};
SharedStruct = module.exports.SharedStruct = function(args) {
  this.key = null;
  this.value = null;
  if (args) {
    if (args.key !== undefined) {
      this.key = args.key;
    }
    if (args.value !== undefined) {
      this.value = args.value;
    }
  }
};
SharedStruct.prototype = {};
SharedStruct.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.I32) {
        this.key = input.readI32();
      } else {
        input.skip(ftype);
      }
      break;
      case 2:
      if (ftype == Thrift.Type.STRING) {
        this.value = input.readString();
      } else {
        input.skip(ftype);
      }
      break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

SharedStruct.prototype.write = function(output) {
  output.writeStructBegin('SharedStruct');
  if (this.key !== null && this.key !== undefined) {
    output.writeFieldBegin('key', Thrift.Type.I32, 1);
    output.writeI32(this.key);
    output.writeFieldEnd();
  }
  if (this.value !== null && this.value !== undefined) {
    output.writeFieldBegin('value', Thrift.Type.STRING, 2);
    output.writeString(this.value);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

