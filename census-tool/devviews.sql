CREATE OR REPLACE VIEW daisi_dev.bird_census_images AS
 SELECT i.session, i.project, i.trc, i.cam, i.img, i.project_list,
        CASE
            WHEN r.max_ready = 1 THEN true
            ELSE false
        END AS examined, i.analysed
   FROM ( SELECT image_properties.session, unnest(image_properties.project_list) AS project, image_properties.project_list, image_properties.analysed, image_properties.trc, image_properties.cam, image_properties.img
           FROM image_properties) i
   LEFT JOIN ( SELECT raw_images.session, raw_images.cam, raw_images.img, max(raw_images.rdy) AS max_ready
           FROM raw_images
          GROUP BY raw_images.session, raw_images.cam, raw_images.img) r ON i.cam = r.cam::text AND i.img = r.img::text AND i.project = r.session::text
  ORDER BY i.session, i.trc, i.cam, i.img;

ALTER TABLE daisi_dev.bird_census_images
  OWNER TO awg;
GRANT ALL ON TABLE daisi_dev.bird_census_images TO awg;
GRANT SELECT ON TABLE daisi_dev.bird_census_images TO daisi;

CREATE OR REPLACE VIEW daisi_dev.bird_census_objects AS
 SELECT raw_census.rcns_id, raw_census.session, raw_census.cam, raw_census.img, raw_census.usr, raw_census.tp, raw_census.ux, raw_census.uy
   FROM raw_census
  WHERE raw_census.mark_delete IS NOT TRUE
  ORDER BY raw_census.session, raw_census.rcns_id;

ALTER TABLE daisi_dev.bird_census_objects
  OWNER TO awg;
GRANT ALL ON TABLE daisi_dev.bird_census_objects TO awg;
GRANT SELECT ON TABLE daisi_dev.bird_census_objects TO daisi;

DROP VIEW daisi_dev.bird_census_markers;
CREATE OR REPLACE VIEW daisi_dev.bird_census_markers AS
SELECT rcns_id, session, cam, img, ST_SetSRID(ST_POINT(ux, uy), 32632) geom FROM raw_census WHERE NOT mark_delete;
GRANT ALL ON TABLE daisi_dev.bird_census_markers TO awg;
GRANT SELECT ON TABLE daisi_dev.bird_census_markers TO daisi;
