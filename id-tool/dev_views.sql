DROP VIEW daisi_dev.bird_view_behaviours;
CREATE VIEW daisi_dev.bird_view_behaviours AS
SELECT
    behaviour_id, behaviour, type, b.class_de, b.description_de, b.version
FROM
    census_behaviours b
LEFT JOIN census_types t ON b.type_id=t.type_id;

DROP VIEW daisi_dev.bird_view_associations;
CREATE VIEW daisi_dev.bird_view_associations AS
SELECT
    association_id, association, type, b.class_de, b.description_de, b.version
FROM
    census_associations b
LEFT JOIN census_types t ON b.type_id=t.type_id;

DROP VIEW daisi_dev.bird_view_ages;
CREATE VIEW daisi_dev.bird_view_ages AS
SELECT
    age_id, age, type, ca.description_de, ca.version
FROM census_ages ca LEFT JOIN census_types ct ON ca.type_id=ct.type_id;

DROP VIEW daisi_dev.bird_view_age_years;
CREATE VIEW daisi_dev.bird_view_age_years AS
SELECT
    age_year_id, age_year, type, ca.description_de, ca.version
FROM census_age_years ca LEFT JOIN census_types ct ON ca.type_id=ct.type_id;

DROP VIEW daisi_dev.bird_view_activities;
CREATE VIEW daisi_dev.bird_view_activities AS
SELECT
    activity_id, activity, type, ca.version
FROM census_activities ca LEFT JOIN census_types ct ON ca.type_id=ct.type_id;

DROP VIEW daisi_dev.bird_view_taxa;
CREATE VIEW daisi_dev.bird_view_taxa AS
SELECT
    c.euring_code_id,
    c.euring_code,
    c.name_de,
    c.name_lat,
    t.type,
    c.seaflag,
    c.version
FROM census_euring_codes c LEFT JOIN census_types t ON c.type_id=t.type_id
ORDER BY seaflag DESC, name_de;

GRANT SELECT ON ALL TABLES IN SCHEMA daisi_dev TO daisi;
