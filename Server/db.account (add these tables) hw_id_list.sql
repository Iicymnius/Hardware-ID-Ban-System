/*
Navicat MySQL Data Transfer

Source Server         : Osmanlı2
Source Server Version : 50505
Source Host           : 192.168.240.77:3306
Source Database       : account

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2021-10-17 06:08:51
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `hw_id_list`
-- ----------------------------
DROP TABLE IF EXISTS `hw_id_list`;
CREATE TABLE `hw_id_list` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(255) DEFAULT NULL,
  `hw_id` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=MyISAM AUTO_INCREMENT=1348 DEFAULT CHARSET=latin1 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of hw_id_list
-- ----------------------------
