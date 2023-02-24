CREATE TABLE tblBUSDPrice (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	timestamp datetime DEFAULT current_timestamp,
	price text
);

CREATE TABLE tblBUSD1MinPercent (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	timestamp	datetime DEFAULT current_timestamp,
	symbol text,
	price	real,
	prevPrice real,
	percent real
);

CREATE TABLE tblBUSD5MinPercent (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	timestamp	datetime DEFAULT current_timestamp,
	symbol text,
	price	real,
	prevPrice real,
	percent real
);

CREATE TABLE tblBUSD10MinPercent (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	timestamp	datetime DEFAULT current_timestamp,
	symbol text,
	price	real,
	prevPrice real,
	percent real
);

CREATE TABLE tblBUSD15MinPercent (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	timestamp	datetime DEFAULT current_timestamp,
	symbol text,
	price	real,
	prevPrice real,
	percent real
);

CREATE TABLE tblBUSD30MinPercent (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	timestamp	datetime DEFAULT current_timestamp,
	symbol text,
	price	real,
	prevPrice real,
	percent real
);

CREATE TABLE tblBUSD60MinPercent (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	timestamp	datetime DEFAULT current_timestamp,
	symbol text,
	price	real,
	prevPrice real,
	percent real
);
